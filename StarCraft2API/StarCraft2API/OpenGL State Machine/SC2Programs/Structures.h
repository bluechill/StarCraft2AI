#ifndef STRUCTURES_H
#define STRUCTURES_H 1

#include <OpenCL/OpenCL.h>

typedef struct
{
	cl_float4* env;
	cl_float4* local_env;
} program_struct;

typedef struct
{
	cl_float4 attrib[16];
} vertex_struct;

typedef struct
{
	int index;
	int size;
	int type;
	int normalize;
	int stride;
	int offset;
} attrib_info_struct;

typedef struct
{
	// Vertex Program Result Struct
	cl_float4 position;
	
	struct
	{
		struct
		{
			cl_float4 primary;
			cl_float4 secondary;
		} front;
		
		struct
		{
			cl_float4 primary;
			cl_float4 secondary;
		} back;
		
	} vert_color;
	
	cl_float4* texcoord;
	
	// Fragment Program Result Struct
	cl_float4* frag_color;
} result_struct;

typedef struct
{
	struct
	{
		cl_float4 primary;
		cl_float4 secondary;
	} color;
	
	cl_float4* texcoord;
	cl_float4 position;
} fragment_struct;

#endif
