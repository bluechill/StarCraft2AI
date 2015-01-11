//
//  main.m
//  InjectorCLI
//
//  Created by Alex Turner on 12/3/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <sys/ptrace.h>
#import <pthread/pthread.h>
#import <mach/mach.h>
#import <sys/event.h>

#include "mach_inject_bundle_pid.h"

#include <sys/sysctl.h>
#include <pwd.h>
#include <mach/mach_init.h>
#include <mach/thread_policy.h>
#include <pthread.h>

typedef struct kinfo_proc kinfo_proc;

static int GetBSDProcessList(kinfo_proc **procList, size_t *procCount)
// Returns a list of all BSD processes on the system.  This routine
// allocates the list and puts it in *procList and a count of the
// number of entries in *procCount.  You are responsible for freeing
// this list (use "free" from System framework).
// On success, the function returns 0.
// On error, the function returns a BSD errno value.
{
	int                 err;
	kinfo_proc *        result;
	bool                done;
	static const int    name[] = { CTL_KERN, KERN_PROC, KERN_PROC_ALL, 0 };
	// Declaring name as const requires us to cast it when passing it to
	// sysctl because the prototype doesn't include the const modifier.
	size_t              length;
	
	//    assert( procList != NULL);
	//    assert(*procList == NULL);
	//    assert(procCount != NULL);
	
	*procCount = 0;
	
	// We start by calling sysctl with result == NULL and length == 0.
	// That will succeed, and set length to the appropriate length.
	// We then allocate a buffer of that size and call sysctl again
	// with that buffer.  If that succeeds, we're done.  If that fails
	// with ENOMEM, we have to throw away our buffer and loop.  Note
	// that the loop causes use to call sysctl with NULL again; this
	// is necessary because the ENOMEM failure case sets length to
	// the amount of data returned, not the amount of data that
	// could have been returned.
	
	result = NULL;
	done = false;
	do {
		assert(result == NULL);
		
		// Call sysctl with a NULL buffer.
		
		length = 0;
		err = sysctl( (int *) name, (sizeof(name) / sizeof(*name)) - 1,
					 NULL, &length,
					 NULL, 0);
		if (err == -1) {
			err = errno;
		}
		
		// Allocate an appropriately sized buffer based on the results
		// from the previous call.
		
		if (err == 0) {
			result = (kinfo_proc*)malloc(length);
			if (result == NULL) {
				err = ENOMEM;
			}
		}
		
		// Call sysctl again with the new buffer.  If we get an ENOMEM
		// error, toss away our buffer and start again.
		
		if (err == 0) {
			err = sysctl( (int *) name, (sizeof(name) / sizeof(*name)) - 1,
						 result, &length,
						 NULL, 0);
			if (err == -1) {
				err = errno;
			}
			if (err == 0) {
				done = true;
			} else if (err == ENOMEM) {
				assert(result != NULL);
				free(result);
				result = NULL;
				err = 0;
			}
		}
	} while (err == 0 && ! done);
	
	// Clean up and establish post conditions.
	
	if (err != 0 && result != NULL) {
		free(result);
		result = NULL;
	}
	*procList = result;
	if (err == 0) {
		*procCount = length / sizeof(kinfo_proc);
	}
	
	assert( (err == 0) == (*procList != NULL) );
	
	return err;
}

NSArray* getBSDProcessList()
{
	kinfo_proc *mylist =NULL;
	size_t mycount = 0;
	GetBSDProcessList(&mylist, &mycount);
	
	NSMutableArray *processes = [NSMutableArray arrayWithCapacity:(int)mycount];
	
	for (int i = 0; i < mycount; i++) {
		struct kinfo_proc *currentProcess = &mylist[i];
		struct passwd *user = getpwuid(currentProcess->kp_eproc.e_ucred.cr_uid);
		NSMutableDictionary *entry = [NSMutableDictionary dictionaryWithCapacity:4];
		
		NSNumber *processID = [NSNumber numberWithInt:currentProcess->kp_proc.p_pid];
		NSString *processName = [NSString stringWithFormat: @"%s",currentProcess->kp_proc.p_comm];
		if (processID)[entry setObject:processID forKey:@"processID"];
		if (processName)[entry setObject:processName forKey:@"processName"];
		
		if (user){
			NSNumber *userID = [NSNumber numberWithUnsignedInt:currentProcess->kp_eproc.e_ucred.cr_uid];
			NSString *userName = [NSString stringWithFormat: @"%s",user->pw_name];
			
			if (userID)[entry setObject:userID forKey:@"userID"];
			if (userName)[entry setObject:userName forKey:@"userName"];
		}
		
		[processes addObject:[NSDictionary dictionaryWithDictionary:entry]];
	}
	free(mylist);
	
	return [NSArray arrayWithArray:processes];
}

int set_my_thread_priority() {
	struct sched_param sp;
 
	memset(&sp, 0, sizeof(struct sched_param));
	sp.sched_priority=31;
	if (pthread_setschedparam(pthread_self(), SCHED_RR, &sp)  == -1) {
		printf("Failed to change priority.\n");
		return -1;
	}
	return 0;
}

const char* bundlePath;
pid_t pid;

int main(int argc, const char * argv[]) {
	@autoreleasepool {
		if (argc != 3)
		{
			NSLog(@"Usage:\t%s --bundle [bundle path]", argv[0]);
			return -1;
		}
		
		bundlePath = argv[2];
		
		if (!bundlePath)
			return 99;
	}
	
	pid_t pid = 0;
	
	while (pid == 0)
	{
		@autoreleasepool
		{
			NSArray* processes = getBSDProcessList();
			
			for (NSDictionary* dict in processes)
			{
				if ([[dict objectForKey:@"processName"] isEqualToString:@"SC2"])
				{
					pid = [[dict objectForKey:@"processID"] intValue];
					break;
				}
			}
		}
	}
	
	mach_inject_bundle_pid(bundlePath, pid);
	
	return 0;
}
