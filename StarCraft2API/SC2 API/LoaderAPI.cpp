//
//  LoaderAPI.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 3/12/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include <ostream>
#include <string>

#include "Logging.h"

extern "C" void set_logging(void* c_log, void* s_log, void* f_log, void* f_ptr_log, void* l)
{
	SC2::Utilities::console_log = (void (*)(std::string format, ...))c_log;
	SC2::Utilities::screen_log = (void (*)(std::string format, ...))s_log;
	SC2::Utilities::file_log = (void (*)(std::string format, ...))f_log;
	SC2::Utilities::file_log_file_ptr = (void (*)(FILE*, std::string format, ...))f_ptr_log;
	SC2::Utilities::log = (void (*)(std::ostream&, std::string format, ...))l;
}
