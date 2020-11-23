#include "framework.h"
#include "TimeMgr.h"
#include "Core.h"
#include <ctime>

CTimeMgr::CTimeMgr()
	: m_llFrequency{}
	, m_llCurCount{}
	, m_llOldCount{}
	, m_dt(0.)
{
}

CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::init()
{
	QueryPerformanceFrequency(&m_llFrequency); // 1초에 타이머가 셀수있는 진동수	
	QueryPerformanceCounter(&m_llOldCount);
}

int CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_dt = (double)(m_llCurCount.QuadPart - m_llOldCount.QuadPart) / (double)m_llFrequency.QuadPart;

	m_llOldCount = m_llCurCount;

	// 1초에 1번 계산
	static double accTime = 0.f;
	accTime += m_dt;
	if (accTime > 1.)
	{
		accTime = 0.;
		m_iFPS = (UINT)(1. / m_dt);
	}
	srand(time(NULL));
	return 0;
}

void CTimeMgr::render(HDC _dc)
{
	wchar_t szFPS[255] = {};
	wsprintf(szFPS, L"FPS : %d", m_iFPS, 255);
	TextOut(_dc, 10, 10, szFPS, wcslen(szFPS));
}
