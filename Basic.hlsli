//�}�e���A��
cbuffer ConstBufferDataMaterial : register(b0)
{
	// �F(RGBA)
	float4 color;
};

// ���_�V�F�[�_�[�̏o�͍\����
// �i���_�V�F�[�_�[����s�N�Z���V�F�[�_�[�ւ̂����Ɏg�p����j
struct VSOutput
{
	float4 svpos : SV_POSITION;	// �V�X�e���p���_���W
	float3 normal : NORMAL;		// �@���x�N�g��
	float2 uv  :TEXCOORD;			// uv�l
};

//3D�ϊ��s��
cbuffer ConstBufferDataTransfrom : register(b1)
{
	matrix mat;	//3D�ϊ��s��
}