// DECLARATIONS

float4 ABS(float4 op0);
float4 ADD(float4 op0, float4 op1);
int ARL(float op0);
float4 CMP(float4 op0, float4 op1, float4 op2);
float4 COS(float op0);
float4 DP3(float4 op0, float4 op1);
float4 DP4(float4 op0, float4 op1);
float4 DPH(float4 op0, float4 op1);
float4 DST(float4 op0, float4 op1);
float4 EX2(float op0);
float4 EXP(float op0);
float4 FLR(float4 op0);
float4 FRC(float4 op0);
float4 KIL(float4 op0);
float4 LG2(float op0);
float4 LIT(float4 op0);
float4 LOG(float op0);
float4 LRP(float4 tmp0, float4 tmp1, float4 tmp2);
float4 MAD(float4 tmp0, float4 tmp1, float4 tmp2);
float4 MAX(float4 tmp0, float4 tmp1);
float4 MIN(float4 tmp0, float4 tmp1);
float4 MOV(float4 op0);
float4 MUL(float4 tmp0, float4 tmp1);
float4 POW(float tmp0, float tmp1);
float4 RCP(float tmp);
float4 RSQ(float op0);
float4 SCS(float op0);
float4 SGE(float4 tmp0, float4 tmp1);
float4 SIN(float tmp);
float4 SLT(float4 tmp0, float4 tmp1);
float4 SUB(float4 tmp0, float4 tmp1);
float SWZ(float4 op0);
float4 TEX(float4 op0);
float4 TXB(float4 op0);
float4 TXP(float4 op0);
float4 XPD(float4 tmp0, float4 tmp1);

// IMPLEMENTATIONS
float4 ABS(float4 op0)
{
	return fabs(op0);
}

float4 ADD(float4 op0, float4 op1)
{
	return op0 + op1;
}

int ARL(float op0)
{
	return floor(op0);
}

float4 CMP(float4 op0, float4 op1, float4 op2)
{
	float4 result;
	result.x = op0.x < 0.0f ? op1.x : op2.x;
	result.y = op0.y < 0.0f ? op1.y : op2.y;
	result.z = op0.z < 0.0f ? op1.z : op2.z;
	result.w = op0.w < 0.0f ? op1.w : op2.w;
	
	return result;
}

float4 COS(float op0)
{
	return cos(op0);
}

float4 DP3(float4 op0, float4 op1)
{
	return (op0.x * op1.x) + (op0.y * op1.y) + (op0.z * op1.z);
}

float4 DP4(float4 op0, float4 op1)
{
	return (op0.x * op1.x) + (op0.y * op1.y) + (op0.z * op1.z) + (op0.w * op1.w);
}

float4 DPH(float4 op0, float4 op1)
{
	return (op0.x * op1.x) + (op0.y * op1.y) + (op0.z * op1.z) + op1.w;
}

float4 DST(float4 op0, float4 op1)
{
	float4 result;
	
	result.x = 1.0f;
	result.y = op0.y * op1.y;
	result.z = op0.z;
	result.w = op1.w;
	
	return result;
}

float4 EX2(float op0)
{
	return pow(2, op0);
}

float4 EXP(float op0)
{
	float4 result;
	
	result.x = pow(2, floor(op0));
	result.y = op0 - floor(op0);
	result.z = pow(2, op0);
	result.w = 1.0f;
	
	return result;
}

float4 FLR(float4 op0)
{
	return floor(op0);
}

float4 FRC(float4 op0)
{
	return op0 - floor(op0);
}

float4 KIL(float4 op0)
{
	return op0;
}

float4 LG2(float op0)
{
	return log2(op0);
}

float4 LIT(float4 op0)
{
#define epsilon 0.0003f
	
	float4 tmp, result;
	tmp = op0;
	if (tmp.x < 0.0f)
		tmp.x = 0.0f;
	if (tmp.y < 0.0f)
		tmp.y = 0.0f;
	if (tmp.w < -(128.0f-epsilon))
		tmp.w = -(128.0f-epsilon);
	else if (tmp.w > 128.0f-epsilon)
		tmp.w = 128.0f-epsilon;
	
	result.x = 1.0f;
	result.y = tmp.x;
	result.z = (tmp.x > 0.0f) ? pow(tmp.y, tmp.w) : 0.0f;
	result.w = 1.0f;
	
	return result;
}

float4 LOG(float op0)
{
	float4 result;
	
	result.x = floor(log2(op0));
	result.y = op0 / pow(2, floor(log2(op0)));
	result.z = log2(op0);
	result.w = 1.0f;
	
	return result;
}

float4 LRP(float4 tmp0, float4 tmp1, float4 tmp2)
{
	float4 result;
	result.x = tmp0.x * tmp1.x + (1.0f - tmp0.x) * tmp2.x;
	result.y = tmp0.y * tmp1.y + (1.0f - tmp0.y) * tmp2.y;
	result.z = tmp0.z * tmp1.z + (1.0f - tmp0.z) * tmp2.z;
	result.w = tmp0.w * tmp1.w + (1.0f - tmp0.w) * tmp2.w;
	
	return result;
}

float4 MAD(float4 tmp0, float4 tmp1, float4 tmp2)
{
	float4 result;
	
	result.x = tmp0.x * tmp1.x + tmp2.x;
	result.y = tmp0.y * tmp1.y + tmp2.y;
	result.z = tmp0.z * tmp1.z + tmp2.z;
	result.w = tmp0.w * tmp1.w + tmp2.w;
	
	return result;
}

float4 MAX(float4 tmp0, float4 tmp1)
{
	float4 result;
	
	result.x = (tmp0.x > tmp1.x) ? tmp0.x : tmp1.x;
	result.y = (tmp0.y > tmp1.y) ? tmp0.y : tmp1.y;
	result.z = (tmp0.z > tmp1.z) ? tmp0.z : tmp1.z;
	result.w = (tmp0.w > tmp1.w) ? tmp0.w : tmp1.w;
	
	return result;
}

float4 MIN(float4 tmp0, float4 tmp1)
{
	float4 result;
	
	result.x = (tmp0.x > tmp1.x) ? tmp1.x : tmp0.x;
	result.y = (tmp0.y > tmp1.y) ? tmp1.y : tmp0.y;
	result.z = (tmp0.z > tmp1.z) ? tmp1.z : tmp0.z;
	result.w = (tmp0.w > tmp1.w) ? tmp1.w : tmp0.w;
	
	return result;
}

float4 MOV(float4 op0)
{
	return op0;
}

float4 MUL(float4 tmp0, float4 tmp1)
{
	float4 result;
	
	result.x = tmp0.x * tmp1.x;
	result.y = tmp0.y * tmp1.y;
	result.z = tmp0.z * tmp1.z;
	result.w = tmp0.w * tmp1.w;
	
	return result;
}

float4 POW(float tmp0, float tmp1)
{
	float4 result;
	
	result.x = pow(tmp0, tmp1);
	result.y = pow(tmp0, tmp1);
	result.z = pow(tmp0, tmp1);
	result.w = pow(tmp0, tmp1);

	return result;
}

float4 RCP(float tmp)
{
	float4 result;
	
	result.x = 1.0f/tmp;
	result.y = 1.0f/tmp;
	result.z = 1.0f/tmp;
	result.w = 1.0f/tmp;
	
	return result;
}

float4 RSQ(float op0)
{
	float4 result;
	float tmp = fabs(op0);
	
	result.x = 1.0f/sqrt(tmp);
	result.y = 1.0f/sqrt(tmp);
	result.z = 1.0f/sqrt(tmp);
	result.w = 1.0f/sqrt(tmp);
	
	return result;
}

float4 SCS(float op0)
{
	float4 result;
	
	result.x = cos(op0);
	result.y = sin(op0);
	
	return result;
}

float4 SGE(float4 tmp0, float4 tmp1)
{
	float4 result;
	
	result.x = (tmp0.x >= tmp1.x) ? 1.0f : 0.0f;
	result.y = (tmp0.y >= tmp1.y) ? 1.0f : 0.0f;
	result.z = (tmp0.z >= tmp1.z) ? 1.0f : 0.0f;
	result.w = (tmp0.w >= tmp1.w) ? 1.0f : 0.0f;
	
	return result;
}

float4 SIN(float tmp)
{
	float4 result;
	
	result.x = sin(tmp);
	result.y = sin(tmp);
	result.z = sin(tmp);
	result.w = sin(tmp);

	return result;
}

float4 SLT(float4 tmp0, float4 tmp1)
{
	float4 result;
	
	result.x = (tmp0.x < tmp1.x) ? 1.0f : 0.0f;
	result.y = (tmp0.y < tmp1.y) ? 1.0f : 0.0f;
	result.z = (tmp0.z < tmp1.z) ? 1.0f : 0.0f;
	result.w = (tmp0.w < tmp1.w) ? 1.0f : 0.0f;
	
	return result;
}

float4 SUB(float4 tmp0, float4 tmp1)
{
	return tmp0 - tmp1;
}

float SWZ(float4 op0)
{
	return op0.x;
}

float4 TEX(float4 op0)
{
	return (float4)(0,0,0,1);
}

float4 TXB(float4 op0)
{
	return (float4)(0,0,0,1);
}

float4 TXP(float4 op0)
{
	return (float4)(0,0,0,1);
}

float4 XPD(float4 tmp0, float4 tmp1)
{
	float4 result;
	
	result.x = tmp0.y * tmp1.z - tmp0.z * tmp1.y;
	result.y = tmp0.z * tmp1.x - tmp0.x * tmp1.z;
	result.z = tmp0.x * tmp1.y - tmp0.y * tmp1.x;

	return result;
}
