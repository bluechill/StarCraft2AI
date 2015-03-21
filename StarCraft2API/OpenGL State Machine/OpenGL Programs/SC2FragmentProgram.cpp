//
//  SC2FragmentProgram.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "SC2FragmentProgram.h"

namespace OpenGL
{
	SC2FragmentProgram::SC2FragmentProgram(SC2_StateMachine* s, GLint max_local_parameters)
	: SC2Program(s, max_local_parameters)
	{
		
	}
	
	std::vector<SC2Program::sc2_result_struct> SC2FragmentProgram::run(size_t vertex_count, size_t offset)
	{
		return {};
	}
}