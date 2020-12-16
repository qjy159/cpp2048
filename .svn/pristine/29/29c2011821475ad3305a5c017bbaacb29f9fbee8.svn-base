#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);

private:
	LARGE_INTEGER	m_llFrequency;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llOldCount;

	double			m_dt;
	UINT			m_iFPS;

public:
	// 1프레임 시간을 얻어옴
	float DeltaTime() { return (float)m_dt; }

public:
	void init();
	int update();
	void render(HDC _dc);
};

