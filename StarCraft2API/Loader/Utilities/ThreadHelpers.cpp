//
//  ThreadHelpers.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/13/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "ThreadHelpers.h"

#include "Logging.h"

#include <mach/mach.h>
#include <pthread/pthread.h>

namespace SC2
{
	namespace Utilities
	{
		void suspend_all_threads()
		{
			kern_return_t err;
			thread_act_array_t thread_list;
			mach_msg_type_number_t thread_count;
			
			err = task_threads(mach_task_self(), &thread_list, &thread_count);
			
			if (err)
			{
				SC2::Utilities::console_log("Unable to get a list of all threads: %i", err);
				return;
			}
			
			SC2::Utilities::console_log("Suspending all other threads.");
			
			thread_port_t my_thread = pthread_mach_thread_np(pthread_self());
			
			thread_act_t* current;
			for (int i = 0;i < thread_count;++i, ++thread_list)
			{
				current = thread_list;
				
				if (*current == my_thread)
					continue;
				
				err = thread_suspend(*current);
				
				if (err)
					SC2::Utilities::console_log("Failed to suspend thread: %i", *current);
			}
			
			SC2::Utilities::console_log("Suspended all other threads.");
		}
		
		void unsuspend_all_threads()
		{
			kern_return_t err;
			thread_act_array_t thread_list;
			mach_msg_type_number_t thread_count;
			
			err = task_threads(mach_task_self(), &thread_list, &thread_count);
			
			if (err)
			{
				SC2::Utilities::console_log("Unable to get a list of all threads: %i", err);
				return;
			}
			
			SC2::Utilities::console_log("Unsuspending all other threads.");
			
			thread_port_t my_thread = pthread_mach_thread_np(pthread_self());
			
			thread_act_t* current;
			for (int i = 0;i < thread_count;++i, ++thread_list)
			{
				current = thread_list;
				
				if (*current == my_thread)
					continue;
				
				err = thread_resume(*current);
				
				if (err)
					SC2::Utilities::console_log("Failed to unsuspend thread: %i", *current);
			}
			
			SC2::Utilities::console_log("Unsuspended all other threads.");
		}
	}
}
