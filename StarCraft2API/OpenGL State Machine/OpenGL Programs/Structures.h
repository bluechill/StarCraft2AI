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
	cl_bool enabled;
	
	cl_int index;
	cl_int size;
	cl_int type_size;
	cl_int normalize;
	cl_int stride;
	cl_ulong offset;
} attrib_info_struct;

struct front_struct
{
	cl_float4 primary;
	cl_float4 secondary;
};

struct back_struct
{
	cl_float4 primary;
	cl_float4 secondary;
};

struct color_struct
{
	struct front_struct front;
	struct back_struct back;
};

typedef struct
{
	cl_float4 position;
	struct color_struct color;
} result_struct;

typedef struct
{
	cl_float4 position;
	struct color_struct color;
	
	cl_float4* texcoord;
} sc2_result_struct;

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
