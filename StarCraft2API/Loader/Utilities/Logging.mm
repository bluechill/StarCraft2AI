//
//  Logging.m
//  StarCraft2API
//
//  Created by Alex Turner on 1/13/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "Logging.h"

#include "SC2Controller.h"

#include <syslog.h>
#include <cstdarg>
#include <vector>

extern SC2Controller* sc2api_controller;

namespace SC2
{
	namespace Utilities
	{
		extern "C" void console_log_internal(std::string format, ...)
		{
			va_list list;
			va_start(list, format);
			
			format.insert(0, "SC2API: ");
			
			vsyslog(LOG_NOTICE, format.c_str(), list);
		}
		
		// From http://stackoverflow.com/questions/69738/c-how-to-get-fprintf-results-as-a-stdstring-w-o-sprintf#69911
		std::string vformat (const char *fmt, va_list ap)
		{
			// Allocate a buffer on the stack that's big enough for us almost
			// all the time.  Be prepared to allocate dynamically if it doesn't fit.
			size_t size = 1024;
			char stackbuf[1024];
			std::vector<char> dynamicbuf;
			char *buf = &stackbuf[0];
			
			while (1) {
				// Try to vsnprintf into our buffer.
				int needed = vsnprintf (buf, size, fmt, ap);
				// NB. C99 (which modern Linux and OS X follow) says vsnprintf
				// failure returns the length it would have needed.  But older
				// glibc and current Windows return -1 for failure, i.e., not
				// telling us how much was needed.
				
				if (needed <= (int)size && needed >= 0) {
					// It fit fine so we're done.
					return std::string (buf, (size_t) needed);
				}
				
				// vsnprintf reported that it wanted to write more characters
				// than we allotted.  So try again using a dynamic buffer.  This
				// doesn't happen very often if we chose our initial size well.
				size = (needed > 0) ? (needed+1) : (size*2);
				dynamicbuf.resize (size);
				buf = &dynamicbuf[0];
			}
		}
		
		extern "C" void screen_log_internal(std::string format, ...)
		{
			NSString* currentString = sc2api_controller.console.string;
			
			va_list ap;
			va_start (ap, format);
			std::string buf = vformat (format.c_str(), ap);
			va_end (ap);
			
			console_log("SC2API Screen Log: %s", buf.c_str());

			currentString = [currentString stringByAppendingFormat:@"%s\n", buf.c_str()];
			
			sc2api_controller.console.string = currentString;
		}
		
		static std::mutex file_mutex;
		static FILE* output;
		
		extern "C" void file_log_internal(std::string format, ...)
		{
			if (output == nullptr)
				output = fopen("/Users/bluechill/Developer/OpenGLInjector/StarCraft2API/SC2 Info/SC2Log.log", "w");
			
			va_list list;
			va_start(list, format);
			
			format.insert(0, "SC2API: ");
			
			va_list ap;
			va_start (ap, format);
			std::string buf = vformat (format.c_str(), ap);
			va_end (ap);
			
			file_log_file_ptr(output, "%s", buf.c_str());
		}
		
		extern "C" void file_log_file_ptr_internal(FILE* file, std::string format, ...)
		{
			va_list list;
			va_start(list, format);
			
			file_mutex.lock();
			vfprintf(file, format.c_str(), list);
			file_mutex.unlock();
		}
		
		extern "C" void log_internal(std::ostream& out, std::string format, ...)
		{
			va_list ap;
			va_start (ap, format);
			std::string buf = vformat (format.c_str(), ap);
			va_end (ap);
			
			out << buf;
		}
	}
}
