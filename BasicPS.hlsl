#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);		// 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0);				// 0番スロットに設定されたサンプラー

float4 main(VSOutput input) : SV_TARGET
{
	float4 texcolor = float4(tex.Sample(smp, input.uv));
	float3 light = normalize(float3(1, -1, 1));									// 右下奥向きのライト
	float diffuse = saturate(dot(-light, input.normal));					// diffuseを[0,1]の範囲にClampする
	float brightness = diffuse + 0.3f;
	//float brightness = dot(-light, input.normal);							// 光源へのベクトルと法線ベクトルの内積
	return float4(texcolor.rgb * brightness, texcolor.a) * color;		// 輝度をRGBに代入して出力

	//return float4(input.normal, 1);	// RGBをそれぞれ法線のXYZ、Aを1で出力
	//return float4(tex.Sample(smp, input.uv) * color);
	//return float4(input.uv, 0, 1);
	//return float4(1, 1, 1, 1);
}

// 旧コード
//float4 main() : SV_TARGET
//{
//	return color;
//	//return float4(1.0f, 1.0f, 1.0f, 1.0f);
//}