
typedef struct
{
	float4* env;
	float4* local_env;
} program_struct;

typedef struct
{
	float4 position;
	float4* weight;
	float4 normal;
	
	struct
	{
		float4 primary;
		float4 secondary;
	} color;
	
	float4 fogcoord;
	float4* texcoord;
	float4* matrixindex;
	float4* attrib;
} vertex_struct;

typedef struct
{
	// Vertex Program Result Struct
	float4 position;
	
	struct
	{
		struct
		{
			float4 primary;
			float4 secondary;
		} front;
		
		struct
		{
			float4 primary;
			float4 secondary;
		} back;
		
	} vert_color;
	
	float4 fogcoord;
	float4 pointsize;
	float4* texcoord;
	
	// Fragment Program Result Struct
	float4* frag_color;
	float4 depth;
} result_struct;

typedef struct
{
	struct
	{
		float4 primary;
		float4 secondary;
	} color;
	
	float4* texcoord;
	float4 fogcoord;
	float4 position;
	float4* clip;
	float4* attrib;
	float4 facing;
} fragment_struct;
