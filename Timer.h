#pragma once
#include <Windows.h>

const ULONG MAX_SAMPLE_COUNT = 50;
//50회의 프레임 처리시간을 누적하여 평균한다.

class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();
	void Tick(float fLockFPS = 0.0f);
	//타이머의 시간을 갱신한다.
	unsigned long GetFrameRate(LPWSTR lpszString = NULL, int nCharacters = 0);
	//프레임 레이트를 반환한다.
	float getTimeElapsed();
	//프레임의 평균 경과 시간을 반환한다.
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