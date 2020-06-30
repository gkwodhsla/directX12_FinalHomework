#pragma once
#include "Timer.h"
#include "stdafx.h"
#include "GameObject.h"
#include "Shader.h"

class CCamera;

class CScene
{
public:
	CScene();
	virtual ~CScene();

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void ReleaseObjects();

	bool ProcessInput();
	void AnimateObjects(float fTimeElapsed);
	void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);

	void ReleaseUploadBuffers();

	ID3D12RootSignature* CreateGraphicsRootSignature(ID3D12Device* pd3dDevice);
	ID3D12RootSignature* GetGraphicsRootSignature();
	CObjectsShader** GetShaders() { return m_ppShaders; }

protected:
	ID3D12RootSignature* m_pd3dGraphicsRootSignature = NULL;
	CObjectsShader** m_ppShaders = NULL;
	int m_nShaders = 0;
};

