//
//  Logging_definitions.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 3/12/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include <string>
#include <stdio.h>

namespace SC2
{
	namespace Utilities
	{
		extern "C" void console_log_internal(std::string format, ...);
		extern "C" void screen_log_internal(std::string format, ...);
		extern "C" void file_log_internal(std::string format, ...);
		extern "C" void file_log_file_ptr_internal(FILE*, std::string format, ...);
		extern "C" void log_internal(std::ostream&, std::string format, ...);
		
		void (*console_log)(std::string format, ...) = console_log_internal;
		void (*screen_log)(std::string format, ...) = screen_log_internal;
		void (*file_log)(std::string format, ...) = file_log_internal;
		void (*file_log_file_ptr)(FILE*, std::string format, ...) = file_log_file_ptr_internal;
		void (*log)(std::ostream&, std::string format, ...) = log_internal;
	};
};
