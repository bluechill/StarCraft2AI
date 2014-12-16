//
//  ContextRetriever.h
//  OpenGLFileLoggerHelper
//
//  Created by Alex Turner on 12/11/14.
//  Copyright (c) 2014 Alex Turner. All rights reserved.
//

#ifndef OpenGLFileLoggerHelper_ContextRetriever_h
#define OpenGLFileLoggerHelper_ContextRetriever_h

#ifdef __cplusplus
extern "C" {
#endif

	struct List
	{
		void* value;
		struct List* next;
	};
	
	extern struct List* contextes;

#ifdef __cplusplus
}
#endif
	
#endif
