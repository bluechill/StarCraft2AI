
struct program_struct
{
	__global float4* env;
	__global float4* local_env;
};

struct vertex_struct
{
	float4 attrib[16];
};

struct attrib_info_struct
{
	bool enabled;
	
	int index;
	int size;
	int type_size;
	int normalize;
	int stride;
	
	unsigned long offset;
};

struct front_struct
{
	float4 primary;
	float4 secondary;
};

struct back_struct
{
	float4 primary;
	float4 secondary;
};

struct color_struct
{
	struct front_struct front;
	struct back_struct back;
};

struct result_struct
{
	float4 position;
	struct color_struct color;
};
