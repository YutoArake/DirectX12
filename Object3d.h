#pragma once
#include <Windows.h>
#include <DirectXTex.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
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

// 定数バッファ用データ構造体（マテリアル）
struct ConstBufferDataMaterial {
	XMFLOAT4 color;	// 色 (RGBA)
};

// 定数バッファ用データ構造体（3D変換行列）
struct ConstBufferDataTransform {
	XMMATRIX mat;		//3D変換行列
};

// 3Dオブジェクト型
struct Object3d {
	// 定数バッファ（行列用）
	ID3D12Resource* constBuffTransform;
	// 定数バッファマップ（行列用）
	ConstBufferDataTransform* constMapTransform;
	// アフィン変換情報
	XMFLOAT3 scale = { 1.0f, 1.0f, 1.0f };
	XMFLOAT3 rotation = { 0.0f, 0.0f, 0.0f };
	XMFLOAT3 position = { 0.0f, 0.0f, 0.0f };
	// ワールド変換行列
	XMMATRIX matWorld;
	// 親オブジェクトへのポインタ
	Object3d* parent = nullptr;
};

// 3Dオブジェクトの初期化
void InitializeObject3d(Object3d* object, ID3D12Device* device);
// オブジェクト更新処理
void UpdateObject3d(Object3d* object, XMMATRIX& matView, XMMATRIX& matProjection);
// オブジェクト描画処理
void DrawObject3d(Object3d* object, ID3D12GraphicsCommandList* commandList, D3D12_VERTEX_BUFFER_VIEW& vbView, D3D12_INDEX_BUFFER_VIEW& ibView, UINT numIndices);

//class Object3d {
//private:
//	// 定数バッファ（行列用）
//	ID3D12Resource* constBuffTransform;
//	// 定数バッファマップ（行列用）
//	ConstBufferDataTransform* constMapTransform;
//	// アフィン変換情報
//	XMFLOAT3 scale = { 1.0f, 1.0f, 1.0f };
//	XMFLOAT3 rotation = { 0.0f, 0.0f, 0.0f };
//	XMFLOAT3 position = { 0.0f, 0.0f, 0.0f };
//	// ワールド変換行列
//	XMMATRIX matWorld;
//	// 親オブジェクトへのポインタ
//	Object3d* parent = nullptr;
//
//public:
//	// 3Dオブジェクトの初期化
//	void InitializeObject3d(ID3D12Device* device);
//	// オブジェクト更新処理
//	void UpdateObject3d(XMMATRIX& matView, XMMATRIX& matProjection);
//	// オブジェクト描画処理
//	void DrawObject3d(ID3D12GraphicsCommandList* commandList, D3D12_VERTEX_BUFFER_VIEW& vbView, D3D12_INDEX_BUFFER_VIEW& ibView, UINT numIndices);
//
//	//アクセッサ
//	void SetParent(Object3d* parent) { this->parent = parent; }
//	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
//	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
//	void SetPosition(XMFLOAT3 position) { this->position = position; }
//};