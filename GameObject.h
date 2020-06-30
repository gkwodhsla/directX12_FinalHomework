#pragma once
#include "Mesh.h"

class CShader;

class CCamera;

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();
private:
	int m_nReferences = 0;
public:
	void AddRef() { m_nReferences++; }
	void Release() { if (--m_nReferences <= 0) delete this; }
	//상수버퍼를 생성한다
	virtual void CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	//상수버퍼의 내용을 갱신한다.
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseShaderVariables();

protected:
	CMesh* m_pMesh = NULL;
	CShader* m_pShader = NULL;
	bool isRendered = true;//현재 객체가 렌더링 대상인가
	float lifeSpan = 0.0f;
	XMFLOAT3 m_xmf3MovingDir;
	float m_fVelocity;

public:
	XMFLOAT4X4 m_xmf4x4World;
	void Rotate(XMFLOAT3* pxmf3Axis, float fAngle);

public:
	void ReleaseUploadBuffers();
	virtual void SetMesh(CMesh* pMesh);
	CMesh* GetMesh() { return m_pMesh; }
	virtual void SetShader(CShader* pShader);
	virtual void Animate(float fTimeElapsed);
	virtual void OnPrepareRender();
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera);
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera, UINT nInstances, D3D12_VERTEX_BUFFER_VIEW d3dInstancingBufferView);
	virtual void SetMovingDirection(XMFLOAT3 xmf3MovingDir) { m_xmf3MovingDir = xmf3MovingDir; }
	virtual XMFLOAT3 GetMovingDirection() { return m_xmf3MovingDir; }
	virtual void SetVelocity(float fVelocity) { m_fVelocity = fVelocity; }
	virtual void SetRotationSpeed(float fRotationSpeed) {}
	virtual void SetRotationAxis(XMFLOAT3 xmf3RotationAxis) {}
	
	virtual void SetIsRendered(bool _isRendered) { isRendered = _isRendered; }
	virtual bool GetIsRendered() { return isRendered; }
	virtual void DecreaseLifeSpan(float ElapsedTime)//큐브는 사라지고나서 다시 생기는거고 총알은 생겻다가 사라짐.
	{
		if (!isRendered)
		{
			lifeSpan -= ElapsedTime;
			if (lifeSpan < 0.0f)
			{
				isRendered = true;
				lifeSpan = 3.0f;
			}
		}
	}


public:
	XMFLOAT3 GetPosition();
	XMFLOAT3 GetLook();
	XMFLOAT3 GetUp();
	XMFLOAT3 GetRight();

	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3 xmf3Position);

	void MoveStrafe(float fDistance = 1.0f);
	void MoveUp(float fDistance = 1.0f);
	void MoveForward(float fDistance = 1.0f);

	void Rotate(float fPitch = 10.0f, float fYaw = 10.0f, float fRoll = 10.0f);

	void AddPosition(float x, float y, float z) { m_xmf4x4World._41 += x; m_xmf4x4World._42 += y; m_xmf4x4World._43 += z; }
};

class CRotatingObject : public CGameObject
{
public:
	CRotatingObject();
	virtual ~CRotatingObject();
private:
	XMFLOAT3 m_xmf3RotationAxis;
	float m_fRotationSpeed;
public:
	virtual void SetRotationSpeed(float fRotationSpeed) { m_fRotationSpeed = fRotationSpeed; }
	virtual void SetRotationAxis(XMFLOAT3 xmf3RotationAxis) {
		m_xmf3RotationAxis =
			xmf3RotationAxis;
	}
	virtual void Animate(float fTimeElapsed);
};


class CBulletObject:public CGameObject
{
public:
	CBulletObject()=default;
	virtual ~CBulletObject()=default;
	virtual void DecreaseLifeSpan(float ElapsedTime)//큐브는 사라지고나서 다시 생기는거고 총알은 생겻다가 사라짐.
	{
		if (isRendered)
		{
			lifeSpan -= ElapsedTime;
			if (lifeSpan < 0.0f)
			{
				isRendered = false;
				lifeSpan = 3.0f;
			}
		}
	}
	virtual void Animate(float fTimeElapsed);
	//총알을 이동방향으로 움직여주고 수명을 계산한다.
};