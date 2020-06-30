#pragma once
#include <Windows.h>

const ULONG MAX_SAMPLE_COUNT = 50;
//50ȸ�� ������ ó���ð��� �����Ͽ� ����Ѵ�.

class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();
	void Tick(float fLockFPS = 0.0f);
	//Ÿ�̸��� �ð��� �����Ѵ�.
	unsigned long GetFrameRate(LPWSTR lpszString = NULL, int nCharacters = 0);
	//������ ����Ʈ�� ��ȯ�Ѵ�.
	float getTimeElapsed();
	//�������� ��� ��� �ð��� ��ȯ�Ѵ�.
private:
	bool m_bHardwareHasPerformanceCounter;
	float m_fTimeScale;
	float m_fTimeElapsed;
	__int64 m_nCurrentTime;
	__int64 m_nLastTime;
	__int64 m_nPerformanceFrequency;

	float m_fFrameTime[MAX_SAMPLE_COUNT];
	ULONG m_nSampleCount;

	unsigned long m_nCurrentFrameRate;
	unsigned long m_nFramePerSecond;
	float m_fFPSTimeElapsed;
};