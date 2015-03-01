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
	public:
		SC2VertexProgram(StateMachine* s, GLint max_local_parameters);
		
		virtual std::vector<SC2Program::result_struct> run();
		
	private:
		friend class OpenGL::StateMachine;
		
		cl_mem m_opencl_attrib_info_array;
		
		attrib_info_struct m_vertex_attribs[16];
	};
}
#endif /* defined(__StarCraft2API__SC2VertexProgram__) */
