//
//  SC2FragmentProgram.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__SC2FragmentProgram__
#define __StarCraft2API__SC2FragmentProgram__

#include "SC2Program.h"

namespace OpenGL
{
	class SC2FragmentProgram : public SC2Program
	{
	public:
		SC2FragmentProgram(SC2_StateMachine* s, GLint max_local_parameters);

		virtual std::vector<SC2Program::sc2_result_struct> run(size_t vertex_count, size_t offset);
	};
}

#endif /* defined(__StarCraft2API__SC2FragmentProgram__) */
