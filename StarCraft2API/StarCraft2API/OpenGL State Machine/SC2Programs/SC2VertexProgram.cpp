//
//  SC2VertexProgram.cpp
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#include "SC2VertexProgram.h"

namespace OpenGL
{
	SC2VertexProgram::SC2VertexProgram(StateMachine* s, GLint max_local_parameters)
	: SC2Program(s, max_local_parameters)
	{
		
	}
	
	std::vector<SC2Program::result> SC2VertexProgram::run()
	{
		return {};
	}
}