#include "Basic.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD)
{
    VSOutput output; // �s�N�Z���V�F�[�_�[�ɓn���l
    output.svpos = mul(mat, pos); // ���W�ɍs�����Z
    //output.svpos = pos;
    output.normal = normal;
    output.uv = uv;
    return output;
}

// ���R�[�h
//float4 main(float4 pos : POSITION) : SV_POSITION
//{
//	return pos;	// *float4(1.0f, 1.0f, 1, 1);
//}