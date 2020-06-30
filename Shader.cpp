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

//래스터라이저 상태를 설정하기 위한 구조체를 반환한다.
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

//깊이-스텐실 검사를 위한 상태를 설정하기 위한 구조체를 반환한다.
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

//블렌딩 상태를 설정하기 위한 구조체를 반환한다.
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

//입력 조립기에게 정점 버퍼의 구조를 알려주기 위한 구조체를 반환한다.
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

//셰이더 소스 코드를 컴파일하여 바이트 코드 구조체를 반환한다.
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

//그래픽스 파이프라인 상태 객체를 생성한다.
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
	//파이프라인에 그래픽스 상태 객체를 설정한다.
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
	if (m_ppBullets)
	{
		for (int j = 0; j < m_nBullets; ++j)
			if (m_ppBullets[j])delete m_ppBullets[j];
		delete[] m_ppBullets;
	}
	if (m_ppParticles)
	{
		for (int j = 0; j < m_nParticles; ++j)
			if (m_ppParticles[j])delete m_ppParticles[j];
		delete[] m_ppParticles;
	}
}

void CObjectsShader::AnimateObjects(float fTimeElapsed)
{
	//여기선 파티클만 애니메이션한다.
	//추후 추가 예정!
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
	//아랫면
	m_ppObjects[1]->SetPosition(-150.0f, 180.0f, -450.0f);
	//윗면
	XMStoreFloat4x4(&m_ppObjects[2]->m_xmf4x4World, XMMatrixMultiply(XMLoadFloat4x4(&m_ppObjects[2]->m_xmf4x4World), XMMatrixRotationRollPitchYaw(0.0f, 0.0f, XMConvertToRadians(90.0f))));
	m_ppObjects[2]->SetPosition(-150.0f, -100.0f, -450.0f);
	//왼면
	XMStoreFloat4x4(&m_ppObjects[3]->m_xmf4x4World, XMMatrixMultiply(XMLoadFloat4x4(&m_ppObjects[3]->m_xmf4x4World), XMMatrixRotationRollPitchYaw(0.0f, 0.0f,XMConvertToRadians(90.0f))));
	m_ppObjects[3]->SetPosition(130.0f, -100.0f, -450.0f);
	//오른면
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
	//정점 정보를 위한 입력 원소이다.
	pd3dInputElementDescs[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	pd3dInputElementDescs[1] = { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
	D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 };
	//인스턴싱 정보를 위한 입력 원소이다.
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
	//인스턴스 정보를 저장할 정점 버퍼를 업로드 힙 유형으로 생성한다.
	m_pd3dcbGameObjects = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL,
		sizeof(VS_VB_INSTANCE) * (m_nObjects), D3D12_HEAP_TYPE_UPLOAD,
		D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
	//정점 버퍼(업로드 힙)에 대한 포인터를 저장한다.
	m_pd3dcbGameObjects->Map(0, NULL, (void**)&m_pcbMappedGameObjects);
	//정점 버퍼에 대한 뷰를 생성한다.
	m_d3dInstancingBufferView.BufferLocation =
		m_pd3dcbGameObjects->GetGPUVirtualAddress();
	m_d3dInstancingBufferView.StrideInBytes = sizeof(VS_VB_INSTANCE);
	m_d3dInstancingBufferView.SizeInBytes = sizeof(VS_VB_INSTANCE) * m_nObjects;


	////인스턴스 정보를 저장할 정점 버퍼를 업로드 힙 유형으로 생성한다.
	//m_pd3dcbGameObjectsBullet = ::CreateBufferResource(pd3dDevice, pd3dCommandList, NULL,
	//	sizeof(VS_VB_INSTANCE) * (m_nBullets), D3D12_HEAP_TYPE_UPLOAD,
	//	D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, NULL);
	////정점 버퍼(업로드 힙)에 대한 포인터를 저장한다.
	//m_pd3dcbGameObjectsBullet->Map(0, NULL, (void**)&m_pcbMappedGameObjectsBullet);
	////정점 버퍼에 대한 뷰를 생성한다.
	//m_d3dInstancingBulletBufferView.BufferLocation =
	//	m_pd3dcbGameObjectsBullet->GetGPUVirtualAddress();
	//m_d3dInstancingBulletBufferView.StrideInBytes = sizeof(VS_VB_INSTANCE);
	//m_d3dInstancingBulletBufferView.SizeInBytes = sizeof(VS_VB_INSTANCE) * m_nBullets;

}
void CInstancingShader::ReleaseShaderVariables()
{
	if (m_pd3dcbGameObjects) m_pd3dcbGameObjects->Unmap(0, NULL);
	if (m_pd3dcbGameObjects) m_pd3dcbGameObjects->Release();
	/*if (m_pd3dcbGameObjectsBullet) m_pd3dcbGameObjectsBullet->Unmap(0,NULL);
	if (m_pd3dcbGameObjectsBullet)m_pd3dcbGameObjectsBullet->Release();*/
}

//인스턴싱 정보(객체의 월드 변환 행렬과 색상)를 정점 버퍼에 복사한다.
void CInstancingShader::UpdateShaderVariables(ID3D12GraphicsCommandList
	* pd3dCommandList)
{
	auto firstColor = Colors::Blue;
	auto secondColor = Colors::Orange;
	auto thirdColor = Colors::Gold;
	for (int j = 0; j < m_nObjects; j++)
	{
		m_pcbMappedGameObjects[j].m_xmColor = (j % 2) ? XMFLOAT4(XMVectorGetX(firstColor),XMVectorGetY(firstColor),XMVectorGetZ(firstColor),1.0f) :
			XMFLOAT4(XMVectorGetX(secondColor), XMVectorGetY(secondColor), XMVectorGetZ(secondColor),1.0f);
		m_pcbMappedGameObjects[j].isVisible = XMFLOAT4(1.0f,0.0f,0.0f,0.0f);
		XMStoreFloat4x4(&m_pcbMappedGameObjects[j].m_xmf4x4Transform,
			XMMatrixTranspose(XMLoadFloat4x4(&m_ppObjects[j]->m_xmf4x4World)));
	}

	/*for (int j = 0; j < m_nBullets; ++j)
	{
		m_pcbMappedGameObjectsBullet[j].m_xmColor = XMFLOAT4(XMVectorGetX(thirdColor), XMVectorGetY(thirdColor), XMVectorGetZ(thirdColor), 1.0f);
		m_pcbMappedGameObjectsBullet[j].isVisible = XMFLOAT4(m_ppBullets[j]->GetIsRendered(), 0.0f, 0.0f, 0.0f);
		XMStoreFloat4x4(&m_pcbMappedGameObjectsBullet[j].m_xmf4x4Transform,
			XMMatrixTranspose(XMLoadFloat4x4(&m_ppBullets[j]->m_xmf4x4World)));
	}*/
}

void CInstancingShader::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList
	* pd3dCommandList) 
{
	m_nObjects = 30;
	m_ppObjects = new CGameObject * [m_nObjects];

	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_real_distribution<>initPos(-100.0f, 100.0f);
	std::uniform_real_distribution<>initRotationAxis(0.0f, 1.0f);
	std::uniform_real_distribution<>initRotationSpeed(30.0f, 150.0f);
	std::uniform_real_distribution<>initMovingDir(-1.0f, 1.0f);
	std::uniform_real_distribution<>initVelocity(10.0f, 20.0f);

	int k = 0;
	CRotatingObject* pRotatingObject = NULL;
	for (int i = 0; i <= m_nObjects; ++i)
	{
		pRotatingObject = new CRotatingObject();
		pRotatingObject->SetPosition(XMFLOAT3(initPos(dre)*0.6, initPos(dre)*0.8f, initPos(dre)*3.0f));
		pRotatingObject->SetRotationAxis(Vector3::Normalize(XMFLOAT3(initRotationAxis(dre), initRotationAxis(dre), initRotationAxis(dre))));
		pRotatingObject->SetRotationSpeed(initRotationSpeed(dre));
		pRotatingObject->SetMovingDirection(Vector3::Normalize(XMFLOAT3(initMovingDir(dre), initMovingDir(dre), initMovingDir(dre))));
		pRotatingObject->SetVelocity(initVelocity(dre));
		m_ppObjects[k++] = pRotatingObject;
	}
	
	//인스턴싱을 사용하여 렌더링하기 위하여 하나의 게임 객체만 메쉬를 가진다.
	CCubeMeshDiffused* pCubeMesh = new CCubeMeshDiffused(pd3dDevice, pd3dCommandList,
		12.0f, 12.0f, 12.0f);

	m_ppObjects[0]->SetMesh(pCubeMesh);
	//인스턴싱을 위한 정점 버퍼와 뷰를 생성한다.
	BoundingSpheres = new BoundingSphere[m_nObjects];

	for (int i = 0; i < m_nObjects; ++i)
	{
		BoundingSpheres[i].Center = m_ppObjects[0]->GetMesh()->GetBoundingSphere().Center;
		BoundingSpheres[i].Radius = m_ppObjects[0]->GetMesh()->GetBoundingSphere().Radius;
	}

	CreateShaderVariables(pd3dDevice, pd3dCommandList);

	//m_nBullets = 20;
	//m_ppBullets = new CGameObject * [m_nBullets];
	//k = 0;
	//CBulletObject* pBulletObject = NULL;
	//for (int i = 0; i <= m_nObjects; ++i)
	//{
	//	pBulletObject = new CBulletObject();
	//	pBulletObject->SetPosition(XMFLOAT3(0.0f,0.0f,0.0f));
	//	pBulletObject->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, 0.0f));
	//	pBulletObject->SetVelocity(30.0f);
	//	pBulletObject->SetIsRendered(false);
	//	m_ppBullets[k++] = pBulletObject;
	//}
	//CCubeMeshDiffused* bCubeMesh = new CCubeMeshDiffused(pd3dDevice, pd3dCommandList,
	//	6.0f, 6.0f, 6.0f);

	//m_ppBullets[0]->SetMesh(bCubeMesh);
}

void CInstancingShader::AnimateObjects(float fTimeElapsed)
{
	//화면에 보이는 메인큐브들을 애니메이션하면서 바운딩구를 업데이트한다.
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

	//벽면과 충돌을 검사하고 만약 충돌했다면 적절한 방향으로 방향을 바꾼다.
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

	//맵에 떠다니는 큐브간 충돌검사와 충돌후 반응
	auto isIntersect = ContainmentType::INTERSECTS;
	for (int j = 0; j < m_nObjects; ++j)
	{
		for (int k = 0; k < m_nObjects; ++k)
		{
			if (j != k)
			{
				if (BoundingSpheres[j].Contains(BoundingSpheres[k])==isIntersect)
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



	/*for (int i = 0; i < m_nBullets; ++i)
	{
		if(m_ppBullets[i]->GetIsRendered())
			m_ppBullets[i]->Animate(fTimeElapsed);
	}*/
	//총알이 스폰되었다면 애니메이션을 진행한다.
}

void CInstancingShader::ReleaseObjects()
{

}

void CInstancingShader::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera
	* pCamera)
{
	CShader::Render(pd3dCommandList, pCamera);
	//모든 게임 객체의 인스턴싱 데이터를 버퍼에 저장한다.
	UpdateShaderVariables(pd3dCommandList);
	//하나의 정점 데이터를 사용하여 모든 게임 객체(인스턴스)들을 렌더링한다.
	m_ppObjects[0]->Render(pd3dCommandList, pCamera, m_nObjects,
		m_d3dInstancingBufferView);

	/*m_ppBullets[0]->Render(pd3dCommandList, pCamera, m_nObjects,
		m_d3dInstancingBufferView);*/
}

void CObjectsShader::SpawnBullet(const XMFLOAT3& playerWorldPos, const XMFLOAT3& playerLook)
{
	for (int i = 0; i < m_nBullets; ++i)
	{
		if (!m_ppBullets[i]->GetIsRendered())
		{
			m_ppBullets[i]->SetIsRendered(true);
			m_ppBullets[i]->SetPosition(playerWorldPos);
			m_ppBullets[i]->SetMovingDirection(playerLook);
			break;
		}
	}
}
