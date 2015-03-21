//
//  SC2VertexProgram.h
//  StarCraft2API
//
//  Created by Alex Turner on 1/22/15.
//  Copyright (c) 2015 Alex Turner. All rights reserved.
//

#ifndef __StarCraft2API__SC2VertexProgram__
#define __StarCraft2API__SC2VertexProgram__

#include "SC2Program.h"
#include "Structures.h"

namespace OpenGL
{
	class SC2VertexProgram : public SC2Program
	{
		SC2VertexProgram();
		
	public:
		SC2VertexProgram(SC2_StateMachine* s, GLint max_local_parameters);
		
		virtual std::vector<SC2Program::sc2_result_struct> run(size_t vertex_count, size_t offset);
		
	private:
		friend class OpenGL::SC2_StateMachine;
	};
}
#endif /* defined(__StarCraft2API__SC2VertexProgram__) */
