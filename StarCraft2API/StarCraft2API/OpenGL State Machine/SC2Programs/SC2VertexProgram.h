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

namespace OpenGL
{
	class SC2VertexProgram : public SC2Program
	{
	public:
		SC2VertexProgram(StateMachine* s, GLint max_local_parameters);
		
		virtual std::vector<result> run();
	};
}
#endif /* defined(__StarCraft2API__SC2VertexProgram__) */
