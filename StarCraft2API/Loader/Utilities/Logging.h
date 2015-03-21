//
//  Logging.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/13/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef StarCraft2API_Logging_h
#define StarCraft2API_Logging_h

#include <string>
#include <iostream>
#include <mutex>

namespace SC2
{
	namespace Utilities
	{		
		extern void (*console_log)(std::string format, ...);
		extern void (*screen_log)(std::string format, ...);
		extern void (*file_log)(std::string format, ...);
		extern void (*file_log_file_ptr)(FILE*, std::string format, ...);
		extern void (*log)(std::ostream&, std::string format, ...);
	}
}

#endif
