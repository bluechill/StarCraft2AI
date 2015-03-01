
typedef struct
{
	float4* env;
	float4* local_env;
} program_struct;

typedef struct
{
//	float4 position;
//	float4* weight;
//	float4 normal;
//	
//	struct
//	{
//		float4 primary;
//		float4 secondary;
//	} color;
//	
//	float4 fogcoord;
//	float4* texcoord;
//	float4* matrixindex;
	float4 attrib[16];
} vertex_struct;

typedef struct
{
	int index;
	int size;
	int type;
	int normalize;
	int stride;
	float4* offset;
} attrib_info_struct;

typedef struct
{
	// Vertex Program Result Struct
	float4 position;
	
	float4* texcoord;
	
	// Fragment Program Result Struct
	float4* frag_color;
} result_struct;

typedef struct
{
	struct
	{
		float4 primary;
		float4 secondary;
	} color;
	
	float4* texcoord;
	float4 position;
} fragment_struct;
