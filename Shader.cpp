#include "Shader.h"
#include <random>


CShader::CShader()
{}

CShader::~CShader()
{
	if (m_ppd3dPipelineStates)
	{
		for (int i = 0; i < m_nPipelineStates; i++) if (m_ppd3dPipelineStates[i])
			m_ppd3dPipelineStates[i]->Release();
		delete[] m_ppd3dPipelineStates;
	}
}

//�����Ͷ����� ���¸� �����ϱ� ���� ����ü�� ��ȯ�Ѵ�.
D3D12_RASTERIZER_DESC CShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_BACK;
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
	return(d3dRasterizerDesc);
}

//����-���ٽ� �˻縦 ���� ���¸� �����ϱ� ���� ����ü�� ��ȯ�Ѵ�.
D3D12_DEPTH_STENCIL_DESC CShader::CreateDepthStencilState()
{
	D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc;
	::ZeroMemory(&d3dDepthStencilDesc, sizeof(D3D12_DEPTH_STENCIL_DESC));
	d3dDepthStencilDesc.DepthEnable = TRUE;
	d3dDepthStencilDesc.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	d3dDepthStencilDesc.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
	d3dDepthStencilDesc.StencilEnable = FALSE;
	d3dDepthStencilDesc.StencilReadMask = 0x00;
	d3dDepthStencilDesc.StencilWriteMask = 0x00;
	d3dDepthStencilDesc.FrontFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.FrontFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	d3dDepthStencilDesc.BackFace.StencilFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilPassOp = D3D12_STENCIL_OP_KEEP;
	d3dDepthStencilDesc.BackFace.StencilFunc = D3D12_COMPARISON_FUNC_NEVER;
	return(d3dDepthStencilDesc);
}

//���� ���¸� �����ϱ� ���� ����ü�� ��ȯ�Ѵ�.
D3D12_BLEND_DESC CShader::CreateBlendState()
{
	D3D12_BLEND_DESC d3dBlendDesc;
	::ZeroMemory(&d3dBlendDesc, sizeof(D3D12_BLEND_DESC));
	d3dBlendDesc.AlphaToCoverageEnable = FALSE;
	d3dBlendDesc.IndependentBlendEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].BlendEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].LogicOpEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].SrcBlend = D3D12_BLEND_ONE;
	d3dBlendDesc.RenderTarget[0].DestBlend = D3D12_BLEND_ZERO;
	d3dBlendDesc.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;
	d3dBlendDesc.RenderTarget[0].SrcBlendAlpha = D3D12_BLEND_ONE;
	d3dBlendDesc.RenderTarget[0].DestBlendAlpha = D3D12_BLEND_ZERO;
	d3dBlendDesc.RenderTarget[0].BlendOpAlpha = D3D12_BLEND_OP_ADD;
	d3dBlendDesc.RenderTarget[0].LogicOp = D3D12_LOGIC_OP_NOOP;
	d3dBlendDesc.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	return(d3dBlendDesc);
}

//�Է� �����⿡�� ���� ������ ������ �˷��ֱ� ���� ����ü�� ��ȯ�Ѵ�.
D3D12_INPUT_LAYOUT_DESC CShader::CreateInputLayout()
{
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = NULL;
	d3dInputLayoutDesc.NumElements = 0;
	return(d3dInputLayoutDesc);
}

D3D12_SHADER_BYTECODE CShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	D3D12_SHADER_BYTECODE d3dShaderByteCode;
	d3dShaderByteCode.BytecodeLength = 0;
	d3dShaderByteCode.pShaderBytecode = NULL;
	return(d3dShaderByteCode);
}
D3D12_SHADER_BYTECODE CShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	D3D12_SHADER_BYTECODE d3dShaderByteCode;
	d3dShaderByteCode.BytecodeLength = 0;
	d3dShaderByteCode.pShaderBytecode = NULL;
	return(d3dShaderByteCode);
}

//���̴� �ҽ� �ڵ带 �������Ͽ� ����Ʈ �ڵ� ����ü�� ��ȯ�Ѵ�.
D3D12_SHADER_BYTECODE CShader::CompileShaderFromFile(const WCHAR* pszFileName, LPCSTR
	pszShaderName, LPCSTR pszShaderProfile, ID3DBlob** ppd3dShaderBlob)
{
	UINT nCompileFlags = 0;
#if defined(_DEBUG)
	nCompileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif
	::D3DCompileFromFile(pszFileName, NULL, NULL, pszShaderName, pszShaderProfile,
		nCompileFlags, 0, ppd3dShaderBlob, NULL);
	D3D12_SHADER_BYTECODE d3dShaderByteCode;
	d3dShaderByteCode.BytecodeLength = (*ppd3dShaderBlob)->GetBufferSize();
	d3dShaderByteCode.pShaderBytecode = (*ppd3dShaderBlob)->GetBufferPointer();
	return(d3dShaderByteCode);
}

//�׷��Ƚ� ���������� ���� ��ü�� �����Ѵ�.
void CShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature
	* pd3dGraphicsRootSignature)
{
	ID3DBlob* pd3dVertexShaderBlob = NULL, * pd3dPixelShaderBlob = NULL;
	D3D12_GRAPHICS_PIPELINE_STATE_DESC d3dPipelineStateDesc;
	::ZeroMemory(&d3dPipelineStateDesc, sizeof(D3D12_GRAPHICS_PIPELINE_STATE_DESC));
	d3dPipelineStateDesc.pRootSignature = pd3dGraphicsRootSignature;
	d3dPipelineStateDesc.VS = CreateVertexShader(&pd3dVertexShaderBlob);
	d3dPipelineStateDesc.PS = CreatePixelShader(&pd3dPixelShaderBlob);
	d3dPipelineStateDesc.RasterizerState = CShader::CreateRasterizerState();
	d3dPipelineStateDesc.BlendState = CreateBlendState();
	d3dPipelineStateDesc.DepthStencilState = CreateDepthStencilState();
	d3dPipelineStateDesc.InputLayout = CreateInputLayout();
	d3dPipelineStateDesc.SampleMask = UINT_MAX;
	d3dPipelineStateDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	d3dPipelineStateDesc.NumRenderTargets = 1;
	d3dPipelineStateDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	d3dPipelineStateDesc.DSVFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	d3dPipelineStateDesc.SampleDesc.Count = 1;
	d3dPipelineStateDesc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;
	pd3dDevice->CreateGraphicsPipelineState(&d3dPipelineStateDesc,
		__uuidof(ID3D12PipelineState), (void**)&m_ppd3dPipelineStates[0]);
	if (pd3dVertexShaderBlob) pd3dVertexShaderBlob->Release();
	if (pd3dPixelShaderBlob) pd3dPixelShaderBlob->Release();
	if (d3dPipelineStateDesc.InputLayout.pInputElementDescs) delete[]
		d3dPipelineStateDesc.InputLayout.pInputElementDescs;
}


void CShader::OnPrepareRender(ID3D12GraphicsCommandList* pd3dCommandList)
{
	//���������ο� �׷��Ƚ� ���� ��ü�� �����Ѵ�.
	pd3dCommandList->SetPipelineState(m_ppd3dPipelineStates[0]);
}
void CShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	OnPrepareRender(pd3dCommandList);
}

void CShader::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList)
{
}
void CShader::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
}
void CShader::UpdateShaderVariable(ID3D12GraphicsCommandList* pd3dCommandList, XMFLOAT4X4
	* pxmf4x4World)
{
	XMFLOAT4X4 xmf4x4World;
	XMStoreFloat4x4(&xmf4x4World, XMMatrixTranspose(XMLoadFloat4x4(pxmf4x4World)));
	pd3dCommandList->SetGraphicsRoot32BitConstants(0, 16, &xmf4x4World, 0);
}
void CShader::ReleaseShaderVariables()
{
}

XMFLOAT3 CShader::ScreenRayToWorldRay(float sX, float sY, CCamera* pCamera)
{
	float xP = (2.0f * sX / pCamera->GetViewport().Width) - 1.0f;
	float yP = (-2.0f * sY / pCamera->GetViewport().Height) + 1.0f;
	float xC = xP / pCamera->GetProjectionMatrix()._11;
	float yC = yP / pCamera->GetProjectionMatrix()._22;

	XMVECTOR det;

	auto viewInverse = XMMatrixInverse(&det, XMLoadFloat4x4(&pCamera->GetViewMatrix()));

	XMFLOAT3 cameraRay(xC, yC, 1.0f);


	XMStoreFloat3(&cameraRay, (XMVector3TransformCoord(XMLoadFloat3(&cameraRay), viewInverse)));

	return cameraRay;
}

CPlayerShader::CPlayerShader()
{
}
CPlayerShader::~CPlayerShader()
{
}

D3D12_INPUT_LAYOUT_DESC CPlayerShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new
		D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];
	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;
	return(d3dInputLayoutDesc);
}

D3D12_SHADER_BYTECODE CPlayerShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSDiffused", "vs_5_1",
		ppd3dShaderBlob));
}
D3D12_SHADER_BYTECODE CPlayerShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSDiffused", "ps_5_1",
		ppd3dShaderBlob));
}

void CPlayerShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature
	* pd3dGraphicsRootSignature)
{
	m_nPipelineStates = 1;
	m_ppd3dPipelineStates = new ID3D12PipelineState * [m_nPipelineStates];
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}


CObjectsShader::CObjectsShader()
{
	
}
CObjectsShader::~CObjectsShader()
{
}



D3D12_INPUT_LAYOUT_DESC CObjectsShader::CreateInputLayout()
{
	UINT nInputElementDescs = 2;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new
		D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];
	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;
	return(d3dInputLayoutDesc);
}

D3D12_SHADER_BYTECODE CObjectsShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSDiffused", "vs_5_1",
		ppd3dShaderBlob));
}
D3D12_SHADER_BYTECODE CObjectsShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSDiffused", "ps_5_1",
		ppd3dShaderBlob));
}

D3D12_RASTERIZER_DESC CObjectsShader::CreateRasterizerState()
{
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_WIREFRAME;
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_NONE;
	d3dRasterizerDesc.FrontCounterClockwise = FALSE;
	d3dRasterizerDesc.DepthBias = 0;
	d3dRasterizerDesc.DepthBiasClamp = 0.0f;
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f;
	d3dRasterizerDesc.DepthClipEnable = TRUE;
	d3dRasterizerDesc.MultisampleEnable = FALSE;
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE;
	d3dRasterizerDesc.ForcedSampleCount = 0;
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
	return(d3dRasterizerDesc);
}

void CObjectsShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature
	* pd3dGraphicsRootSignature)
{
	m_nPipelineStates = 1;
	m_ppd3dPipelineStates = new ID3D12PipelineState * [m_nPipelineStates];

	ID3DBlob* pd3dVertexShaderBlob = NULL, * pd3dPixelShaderBlob = NULL;
	D3D12_GRAPHICS_PIPELINE_STATE_DESC d3dPipelineStateDesc;
	::ZeroMemory(&d3dPipelineStateDesc, sizeof(D3D12_GRAPHICS_PIPELINE_STATE_DESC));
	d3dPipelineStateDesc.pRootSignature = pd3dGraphicsRootSignature;
	d3dPipelineStateDesc.VS = CreateVertexShader(&pd3dVertexShaderBlob);
	d3dPipelineStateDesc.PS = CreatePixelShader(&pd3dPixelShaderBlob);
	d3dPipelineStateDesc.RasterizerState = CreateRasterizerState();
	d3dPipelineStateDesc.BlendState = CreateBlendState();
	d3dPipelineStateDesc.DepthStencilState = CreateDepthStencilState();
	d3dPipelineStateDesc.InputLayout = CreateInputLayout();
	d3dPipelineStateDesc.SampleMask = UINT_MAX;
	d3dPipelineStateDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	d3dPipelineStateDesc.NumRenderTargets = 1;
	d3dPipelineStateDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	d3dPipelineStateDesc.DSVFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	d3dPipelineStateDesc.SampleDesc.Count = 1;
	d3dPipelineStateDesc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;
	pd3dDevice->CreateGraphicsPipelineState(&d3dPipelineStateDesc,
		__uuidof(ID3D12PipelineState), (void**)&m_ppd3dPipelineStates[0]);
	if (pd3dVertexShaderBlob) pd3dVertexShaderBlob->Release();
	if (pd3dPixelShaderBlob) pd3dPixelShaderBlob->Release();
	if (d3dPipelineStateDesc.InputLayout.pInputElementDescs) delete[]
		d3dPipelineStateDesc.InputLayout.pInputElementDescs;
}



void CObjectsShader::ReleaseObjects()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++)
		{
			if (m_ppObjects[j]) delete m_ppObjects[j];
		}
		delete[] m_ppObjects;
	}
}

void CObjectsShader::AnimateObjects(float fTimeElapsed)
{
	
}

void CObjectsShader::ReleaseUploadBuffers()
{
	if (m_ppObjects)
	{
		for (int j = 0; j < m_nObjects; j++) m_ppObjects[j]->ReleaseUploadBuffers();
	}
}

void CObjectsShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	CShader::Render(pd3dCommandList, pCamera);
	for (int j = 0; j < m_nObjects; j++)
	{
		if (m_ppObjects[j])
		{
			m_ppObjects[j]->Render(pd3dCommandList, pCamera);
		}
	}
}

void CObjectsShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList)
{
	int k = 0;
	m_nObjects = 4;
	m_ppObjects = new CGameObject * [m_nObjects];
	CPlaneMeshDiffused* pPlaneMesh = new CPlaneMeshDiffused(pd3dDevice, pd3dCommandList);
	for (int i = 0; i < m_nObjects; ++i)
	{
		m_ppObjects[i] = new CGameObject();
		m_ppObjects[i]->SetMesh(pPlaneMesh);
	}
	m_ppObjects[0]->SetPosition(-150.0f, -100.0f, -450.0f);
	//�Ʒ���
	m_ppObjects[1]->SetPosition(-150.0f, 180.0f, -450.0f);
	//����
	XMStoreFloat4x4(&m_ppObjects[2]->m_xmf4x4World, XMMatrixMultiply(XMLoadFloat4x4(&m_ppObjects[2]->m_xmf4x4World), XMMatrixRotationRollPitchYaw(0.0f, 0.0f, XMConvertToRadians(90.0f))));
	m_ppObjects[2]->SetPosition(-150.0f, -100.0f, -450.0f);
	//�޸�
	XMStoreFloat4x4(&m_ppObjects[3]->m_xmf4x4World, XMMatrixMultiply(XMLoadFloat4x4(&m_ppObjects[3]->m_xmf4x4World), XMMatrixRotationRollPitchYaw(0.0f, 0.0f,XMConvertToRadians(90.0f))));
	m_ppObjects[3]->SetPosition(130.0f, -100.0f, -450.0f);
	//������
	CreateShaderVariables(pd3dDevice, pd3dCommandList);
}
CInstancingShader::CInstancingShader()
{

}
CInstancingShader::~CInstancingShader()
{
	delete[] BoundingSpheres;
}

D3D12_INPUT_LAYOUT_DESC CInstancingShader::CreateInputLayout()
{
	UINT nInputElementDescs = 8;
	D3D12_INPUT_ELEMENT_DESC* pd3dInputElementDescs = new
		D3D12_INPUT_ELEMENT_DESC[nInputElementDescs];
	//���� ������ ���� �Է� �����̴�.
	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//�ν��Ͻ� ������ ���� �Է� �����̴�.
	pd3dInputElementDescs[2] = { "WORLDMATRIX", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 0,
	D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 };
	pd3dInputElementDescs[3] = { "WORLDMATRIX", 1, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 16,
	D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 };
	pd3dInputElementDescs[4] = { "WORLDMATRIX", 2, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 32,
	D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 };
	pd3dInputElementDescs[5] = { "WORLDMATRIX", 3, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 48,
	D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 };
	pd3dInputElementDescs[6] = { "INSTANCECOLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1,
	64, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 };
	pd3dInputElementDescs[7] = { "VISIBILITY", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1,
	80, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 };
	D3D12_INPUT_LAYOUT_DESC d3dInputLayoutDesc;
	d3dInputLayoutDesc.pInputElementDescs = pd3dInputElementDescs;
	d3dInputLayoutDesc.NumElements = nInputElementDescs;
	return(d3dInputLayoutDesc);
}

D3D12_SHADER_BYTECODE CInstancingShader::CreateVertexShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "VSInstancing", "vs_5_1",
		ppd3dShaderBlob));
}
D3D12_SHADER_BYTECODE CInstancingShader::CreatePixelShader(ID3DBlob** ppd3dShaderBlob)
{
	return(CShader::CompileShaderFromFile(L"Shaders.hlsl", "PSInstancing", "ps_5_1",
		ppd3dShaderBlob));
}
void CInstancingShader::CreateShader(ID3D12Device* pd3dDevice, ID3D12RootSignature
	* pd3dGraphicsRootSignature)
{
	m_nPipelineStates = 1;
	m_ppd3dPipelineStates = new ID3D12PipelineState * [m_nPipelineStates];
	CShader::CreateShader(pd3dDevice, pd3dGraphicsRootSignature);
}

void CInstancingShader::CreateShaderVariables(ID3D12Device* pd3dDevice,
	ID3D12GraphicsCommandList* pd3dCommandList)
{
	//�ν��Ͻ� ������ ������ ���� ���۸� ���ε� �� �������� �����Ѵ�.
	m_pd3dcbGameObjects = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL,
		sizeof(VS_VB_INSTANCE) * (m_nObjects + m_nBullets + m_nParticles), D3D12_HEAP_TYPE_UPLOAD,
		D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
	//���� ����(���ε� ��)�� ���� �����͸� �����Ѵ�.
	m_pd3dcbGameObjects->Map(0, NULL, (void**)&m_pcbMappedGameObjects);
	//���� ���ۿ� ���� �並 �����Ѵ�.
	m_d3dInstancingBufferView.BufferLocation =
		m_pd3dcbGameObjects->GetGPUVirtualAddress();
	m_d3dInstancingBufferView.StrideInBytes = sizeof(VS_VB_INSTANCE);
	m_d3dInstancingBufferView.SizeInBytes = sizeof(VS_VB_INSTANCE) * (m_nObjects + m_nBullets + m_nParticles);

}
void CInstancingShader::ReleaseShaderVariables()
{
	if (m_pd3dcbGameObjects) m_pd3dcbGameObjects->Unmap(0, NULL);
	if (m_pd3dcbGameObjects) m_pd3dcbGameObjects->Release();
}

//�ν��Ͻ� ����(��ü�� ���� ��ȯ ��İ� ����)�� ���� ���ۿ� �����Ѵ�.
void CInstancingShader::UpdateShaderVariables(ID3D12GraphicsCommandList
	* pd3dCommandList)
{
	auto firstColor = Colors::Blue;
	auto secondColor = Colors::Green;
	auto thirdColor = Colors::Red;
	auto fourthColor = Colors::Gold;
	for (int j = 0; j < m_nObjects; j++)
	{
		m_pcbMappedGameObjects[j].m_xmColor = (j % 2) ? XMFLOAT4(XMVectorGetX(firstColor),XMVectorGetY(firstColor),XMVectorGetZ(firstColor),1.0f) :
			XMFLOAT4(XMVectorGetX(secondColor), XMVectorGetY(secondColor), XMVectorGetZ(secondColor),1.0f);
		m_pcbMappedGameObjects[j].isVisible = XMFLOAT4(m_ppObjects[j]->GetIsRendered(),0.0f,0.0f,0.0f);
		XMStoreFloat4x4(&m_pcbMappedGameObjects[j].m_xmf4x4Transform,
			XMMatrixTranspose(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World)));
	}

	for (int j = m_nObjects; j < m_nObjects + m_nBullets; ++j)
	{
		m_pcbMappedGameObjects[j].m_xmColor = XMFLOAT4(XMVectorGetX(thirdColor), XMVectorGetY(thirdColor), XMVectorGetZ(thirdColor), 1.0f);
		m_pcbMappedGameObjects[j].isVisible = XMFLOAT4(m_ppObjects[j]->GetIsRendered(), 0.0f, 0.0f, 0.0f);
		auto scailingWorld = XMMatrixMultiply(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World), XMMatrixScaling(0.2f, 0.2f, 0.2f));
		XMStoreFloat4x4(&m_pcbMappedGameObjects[j].m_xmf4x4Transform,
			XMMatrixTranspose(scailingWorld));
	}

	for (int j = m_nObjects + m_nBullets;j<m_nObjects+m_nBullets+m_nParticles ;++j)
	{
		m_pcbMappedGameObjects[j].m_xmColor = XMFLOAT4(XMVectorGetX(fourthColor), XMVectorGetY(fourthColor), XMVectorGetZ(fourthColor), 1.0f);
		m_pcbMappedGameObjects[j].isVisible = XMFLOAT4(m_ppObjects[j]->GetIsRendered(), 0.0f, 0.0f, 0.0f);
		auto scailingWorld = XMMatrixMultiply(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World), XMMatrixScaling(0.2f, 0.2f, 0.2f));
		XMStoreFloat4x4(&m_pcbMappedGameObjects[j].m_xmf4x4Transform,
			XMMatrixTranspose(scailingWorld));
	}
	
}

void CInstancingShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList) 
{
	m_nObjects = 25;
	m_nBullets = 15;
	m_nParticles = 250;
	m_ppObjects = new CGameObject * [m_nObjects+m_nBullets+m_nParticles];

	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_real_distribution<>initPos(-100.0f, 100.0f);
	std::uniform_real_distribution<>initRotationAxis(0.0f, 1.0f);
	std::uniform_real_distribution<>initRotationSpeed(30.0f, 150.0f);
	std::uniform_real_distribution<>initMovingDir(-1.0f, 1.0f);
	std::uniform_real_distribution<>initVelocity(20.0f, 50.0f);

	int k = 0;
	CRotatingObject* pRotatingObject = NULL;
	for (int i = 0; i < m_nObjects; ++i)
	{
		pRotatingObject = new CRotatingObject();
		pRotatingObject->SetPosition(XMFLOAT3(initPos(dre)*0.6, initPos(dre)*0.8f, initPos(dre)*3.0f));
		pRotatingObject->SetRotationAxis(Vector3::Normalize(XMFLOAT3(initRotationAxis(dre), initRotationAxis(dre), initRotationAxis(dre))));
		pRotatingObject->SetRotationSpeed(initRotationSpeed(dre));
		pRotatingObject->SetMovingDirection(Vector3::Normalize(XMFLOAT3(initMovingDir(dre), initMovingDir(dre), initMovingDir(dre))));
		pRotatingObject->SetVelocity(initVelocity(dre));
		m_ppObjects[k++] = pRotatingObject;
	}
	
	for (int i = 0; i < m_nBullets; ++i)
	{
		pRotatingObject = new CBulletObject();
		pRotatingObject->SetPosition(0.0f,0.0f,0.0f);
		pRotatingObject->SetRotationAxis(Vector3::Normalize(XMFLOAT3(initRotationAxis(dre), initRotationAxis(dre), initRotationAxis(dre))));
		pRotatingObject->SetRotationSpeed(1000.0f);
		pRotatingObject->SetMovingDirection(XMFLOAT3(0.0f,0.0f,0.0f));
		pRotatingObject->SetVelocity(500.0f);
		pRotatingObject->SetIsRendered(false);
		m_ppObjects[k++] = pRotatingObject;
	}

	for (int i = 0; i < m_nParticles;++i)
	{
		pRotatingObject = new CBulletObject();
		pRotatingObject->SetPosition(0.0f, 0.0f, 0.0f);
		pRotatingObject->SetRotationAxis(Vector3::Normalize(XMFLOAT3(initRotationAxis(dre), initRotationAxis(dre), initRotationAxis(dre))));
		pRotatingObject->SetRotationSpeed(1500.0f);
		pRotatingObject->SetMovingDirection(Vector3::Normalize(XMFLOAT3(initMovingDir(dre), initMovingDir(dre), initMovingDir(dre))));
		pRotatingObject->SetVelocity(1000.0f);
		pRotatingObject->SetIsRendered(false);
		m_ppObjects[k++] = pRotatingObject;
	}

	//�ν��Ͻ��� ����Ͽ� �������ϱ� ���Ͽ� �ϳ��� ���� ��ü�� �޽��� ������.
	CCubeMeshDiffused* pCubeMesh = new CCubeMeshDiffused(pd3dDevice, pd3dCommandList,
		12.0f, 12.0f, 12.0f);
	m_ppObjects[0]->SetMesh(pCubeMesh);

	BoundingSpheres = new BoundingSphere[m_nObjects+m_nBullets];
	//��ƼŬ�� �浹��ü�� ������ �ʴ´�.
	for (int i = 0; i < m_nObjects+m_nBullets; ++i)
	{
		BoundingSpheres[i].Center = m_ppObjects[0]->GetMesh()->GetBoundingSphere().Center;
		BoundingSpheres[i].Radius = m_ppObjects[0]->GetMesh()->GetBoundingSphere().Radius;
	}

	//�ν��Ͻ��� ���� ���� ���ۿ� �並 �����Ѵ�.
	CreateShaderVariables(pd3dDevice, pd3dCommandList);
}

void CInstancingShader::AnimateObjects(float fTimeElapsed)
{
	//ȭ�鿡 ���̴� ����ť����� �ִϸ��̼��ϸ鼭 �ٿ������ ������Ʈ�Ѵ�.
	for (int j = 0; j < m_nObjects; ++j)
	{
		m_ppObjects[j]->Animate(fTimeElapsed);
		BoundingSpheres[j].Transform(BoundingSpheres[j], 0.0f, XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f),
			XMVectorSet(m_ppObjects[j]->m_xmf4x4World._41, m_ppObjects[j]->m_xmf4x4World._42, m_ppObjects[j]->m_xmf4x4World._43, 1.0f));
		BoundingSpheres[j].Radius=8.0f;
	}
	auto check = PlaneIntersectionType::INTERSECTING;
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_real_distribution<> urd(-0.5f, 0.5f);

	//����� �浹�� �˻��ϰ� ���� �浹�ߴٸ� ������ �������� ������ �ٲ۴�.
	for (int j = 0; j < m_nObjects; ++j)
	{
		if (BoundingSpheres[j].Intersects(Plane::lowPlane) == check)
		{
			m_ppObjects[j]->SetMovingDirection(Vector3::Normalize(XMFLOAT3(urd(dre), 1.0f, urd(dre))));
		}
		else if (BoundingSpheres[j].Intersects(Plane::highPlane) == check)
		{
			m_ppObjects[j]->SetMovingDirection(Vector3::Normalize(XMFLOAT3(urd(dre), -1.0f, urd(dre))));
		}
		else if (BoundingSpheres[j].Intersects(Plane::leftPlane) == check)
		{
			m_ppObjects[j]->SetMovingDirection(Vector3::Normalize(XMFLOAT3(1.0f, urd(dre), urd(dre))));
		}
		else if (BoundingSpheres[j].Intersects(Plane::rightPlane) == check)
		{
			m_ppObjects[j]->SetMovingDirection(Vector3::Normalize(XMFLOAT3(-1.0f, urd(dre), urd(dre))));
		}
	}

	//�ʿ� ���ٴϴ� ť�갣 �浹�˻�� �浹�� ����
	auto isIntersect = ContainmentType::INTERSECTS;
	for (int j = 0; j < m_nObjects; ++j)
	{
		for (int k = 0; k < m_nObjects; ++k)
		{
			if (j != k)
			{
				if (m_ppObjects[j]->GetIsRendered() && BoundingSpheres[j].Contains(BoundingSpheres[k])==isIntersect)
				{
					auto curDir = m_ppObjects[j]->GetMovingDirection();
					curDir = Vector3::ScalarProduct(curDir, -1.0f, true);
					m_ppObjects[j]->SetMovingDirection(curDir);
					m_ppObjects[j]->AddPosition(curDir.x * 2.0f, curDir.y * 2.0f, curDir.z * 2.0f);
					BoundingSpheres[j].Transform(BoundingSpheres[j], 0.0f, XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f),
						XMVectorSet(m_ppObjects[j]->m_xmf4x4World._41, m_ppObjects[j]->m_xmf4x4World._42, m_ppObjects[j]->m_xmf4x4World._43, 1.0f));
					BoundingSpheres[j].Radius = 8.0f;

					curDir = m_ppObjects[k]->GetMovingDirection();
					curDir = Vector3::ScalarProduct(curDir, -1.0f, true);
					m_ppObjects[k]->SetMovingDirection(curDir);
					m_ppObjects[k]->AddPosition(curDir.x * 2.0f, curDir.y * 2.0f, curDir.z * 2.0f);
					BoundingSpheres[k].Transform(BoundingSpheres[k], 0.0f, XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f),
						XMVectorSet(m_ppObjects[k]->m_xmf4x4World._41, m_ppObjects[k]->m_xmf4x4World._42, m_ppObjects[k]->m_xmf4x4World._43, 1.0f));
					BoundingSpheres[k].Radius = 8.0f;
				}
			}
		}
	}


	//�Ѿ��� �����Ǿ��ٸ� �ִϸ��̼ǰ� ť�갣 �浹ó���� �����Ѵ�.
	for (int i = m_nObjects; i < m_nObjects + m_nBullets; ++i)
	{
		if (m_ppObjects[i]->GetIsRendered())
		{
			m_ppObjects[i]->Animate(fTimeElapsed);
			BoundingSpheres[i].Transform(BoundingSpheres[i], 0.0f, XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f),
				XMVectorSet(m_ppObjects[i]->m_xmf4x4World._41*0.2f, m_ppObjects[i]->m_xmf4x4World._42 * 0.2f, m_ppObjects[i]->m_xmf4x4World._43 * 0.2f, 1.0f));
			//���庯ȯ�� 5�踦 �� �����̹Ƿ� 0.2�� ���Ѵ�.
			BoundingSpheres[i].Radius = 2.0f;

			for (int j = 0; j < m_nObjects; ++j)
			{
				if (m_ppObjects[j]->GetIsRendered() && BoundingSpheres[j].Contains(BoundingSpheres[i])==isIntersect)
				{
					m_ppObjects[i]->SetLifeSapn(0.0f);
					//�Ѿ��� ������ 0�ʷ� ����� �ı��ϰ�
					m_ppObjects[j]->SetIsRendered(false);
					//�浹�� ť�긦 ȭ��󿡼� ��� �����.

					for (int k = 0; k < m_nParticles; k += 50)
					{
						if (!m_ppObjects[m_nObjects + m_nBullets + k]->GetIsRendered())
						{
							for (int l = k; l < k + 50; ++l)
							{
								m_ppObjects[m_nObjects + m_nBullets + l]->SetPosition(BoundingSpheres[j].Center.x*5.0f, BoundingSpheres[j].Center.y * 5.0f, BoundingSpheres[j].Center.z * 5.0f);
								m_ppObjects[m_nObjects + m_nBullets + l]->SetIsRendered(true);
							}
							break;
						}
					}
				}
			}
		}
	}



	//��ƼŬ�� �����Ǿ��ٸ� ��ƼŬ �ִϸ��̼��� �����Ѵ�.
	for (int i = m_nObjects + m_nBullets; i < m_nObjects + m_nBullets + m_nParticles; i+=50)
	{
		if (m_ppObjects[i]->GetIsRendered())
		{
			for(int j=i;j<i+50;++j)
				m_ppObjects[j]->Animate(fTimeElapsed);
		}
	}
}

void CInstancingShader::ReleaseObjects()
{

}

void CInstancingShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera
	* pCamera)
{
	CShader::Render(pd3dCommandList, pCamera);
	//��� ���� ��ü�� �ν��Ͻ� �����͸� ���ۿ� �����Ѵ�.
	UpdateShaderVariables(pd3dCommandList);
	//�ϳ��� ���� �����͸� ����Ͽ� ��� ���� ��ü(�ν��Ͻ�)���� �������Ѵ�.
	m_ppObjects[0]->Render(pd3dCommandList, pCamera, m_nObjects+m_nBullets+m_nParticles,
		m_d3dInstancingBufferView);
}

void CObjectsShader::SpawnBullet(const XMFLOAT3& playerWorldPos, const XMFLOAT3& playerLook, bool isGuidedBullet, int cubeIndex)
{
	for (int i = m_nObjects; i < m_nObjects+m_nBullets; ++i)
	{
		if (!m_ppObjects[i]->GetIsRendered())
		{
			m_ppObjects[i]->SetIsRendered(true);
			m_ppObjects[i]->SetIsGuided(isGuidedBullet);
			if(cubeIndex!=INT_MAX)
				m_ppObjects[i]->SetTargetCube(m_ppObjects[cubeIndex]);
			float x = playerWorldPos.x;
			float y = playerWorldPos.y;
			float z = playerWorldPos.z;

			m_ppObjects[i]->SetPosition(x*5.0f,y*5.0f,z*5.0f);
			//�Ѿ��� ũ�⸦ 0.2��ŭ �ٿ��Z�⶧���� 5.0�� ���ؼ� �������ش�.
			m_ppObjects[i]->SetMovingDirection(playerLook);
			break;
		}
	}
}

std::pair<bool, int> CInstancingShader::CheckRayIntersect(XMFLOAT3& worldRay, XMFLOAT3& worldCameraPos)
{
	float distance;

	auto result = XMVector3Normalize(XMVectorSubtract(XMLoadFloat3(&worldRay),
		XMLoadFloat3(&worldCameraPos)));

	for (int i = 0; i < m_nObjects; ++i)
	{
		if (m_ppObjects[i]->GetIsRendered() && BoundingSpheres[i].Intersects(XMLoadFloat3(&worldCameraPos), result, distance))
			return std::make_pair(true, i);
	}
	return std::make_pair(false, INT_MAX);
}