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
	SC2FragmentProgram::SC2FragmentProgram(StateMachine* s, GLint max_local_parameters)
	: SC2Program(s, max_local_parameters)
	{
		
	}
	
	std::vector<SC2Program::result> SC2FragmentProgram::run()
	{
		return {};
	}
}