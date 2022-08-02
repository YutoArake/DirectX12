#pragma once
#include <Windows.h>
#include <DirectXTex.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <dinput.h>
#include <cassert>
#include <vector>
#include <string>
#include <DirectXMath.h>
using namespace DirectX;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

// �萔�o�b�t�@�p�f�[�^�\���́i�}�e���A���j
struct ConstBufferDataMaterial {
	XMFLOAT4 color;	// �F (RGBA)
};

// �萔�o�b�t�@�p�f�[�^�\���́i3D�ϊ��s��j
struct ConstBufferDataTransform {
	XMMATRIX mat;		//3D�ϊ��s��
};

// 3D�I�u�W�F�N�g�^
struct Object3d {
	// �萔�o�b�t�@�i�s��p�j
	ID3D12Resource* constBuffTransform;
	// �萔�o�b�t�@�}�b�v�i�s��p�j
	ConstBufferDataTransform* constMapTransform;
	// �A�t�B���ϊ����
	XMFLOAT3 scale = { 1.0f, 1.0f, 1.0f };
	XMFLOAT3 rotation = { 0.0f, 0.0f, 0.0f };
	XMFLOAT3 position = { 0.0f, 0.0f, 0.0f };
	// ���[���h�ϊ��s��
	XMMATRIX matWorld;
	// �e�I�u�W�F�N�g�ւ̃|�C���^
	Object3d* parent = nullptr;
};

// 3D�I�u�W�F�N�g�̏�����
void InitializeObject3d(Object3d* object, ID3D12Device* device);
// �I�u�W�F�N�g�X�V����
void UpdateObject3d(Object3d* object, XMMATRIX& matView, XMMATRIX& matProjection);
// �I�u�W�F�N�g�`�揈��
void DrawObject3d(Object3d* object, ID3D12GraphicsCommandList* commandList, D3D12_VERTEX_BUFFER_VIEW& vbView, D3D12_INDEX_BUFFER_VIEW& ibView, UINT numIndices);

//class Object3d {
//private:
//	// �萔�o�b�t�@�i�s��p�j
//	ID3D12Resource* constBuffTransform;
//	// �萔�o�b�t�@�}�b�v�i�s��p�j
//	ConstBufferDataTransform* constMapTransform;
//	// �A�t�B���ϊ����
//	XMFLOAT3 scale = { 1.0f, 1.0f, 1.0f };
//	XMFLOAT3 rotation = { 0.0f, 0.0f, 0.0f };
//	XMFLOAT3 position = { 0.0f, 0.0f, 0.0f };
//	// ���[���h�ϊ��s��
//	XMMATRIX matWorld;
//	// �e�I�u�W�F�N�g�ւ̃|�C���^
//	Object3d* parent = nullptr;
//
//public:
//	// 3D�I�u�W�F�N�g�̏�����
//	void InitializeObject3d(ID3D12Device* device);
//	// �I�u�W�F�N�g�X�V����
//	void UpdateObject3d(XMMATRIX& matView, XMMATRIX& matProjection);
//	// �I�u�W�F�N�g�`�揈��
//	void DrawObject3d(ID3D12GraphicsCommandList* commandList, D3D12_VERTEX_BUFFER_VIEW& vbView, D3D12_INDEX_BUFFER_VIEW& ibView, UINT numIndices);
//
//	//�A�N�Z�b�T
//	void SetParent(Object3d* parent) { this->parent = parent; }
//	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
//	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
//	void SetPosition(XMFLOAT3 position) { this->position = position; }
//};