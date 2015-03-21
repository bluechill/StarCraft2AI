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
		void (*console_log)(std::string format, ...) = nullptr;
		void (*screen_log)(std::string format, ...) = nullptr;
		void (*file_log)(std::string format, ...) = nullptr;
		void (*file_log_file_ptr)(FILE*, std::string format, ...) = nullptr;
		void (*log)(std::ostream&, std::string format, ...) = nullptr;
	};
};
