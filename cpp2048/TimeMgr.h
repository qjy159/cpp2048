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
	// 1������ �ð��� ����
	float DeltaTime() { return (float)m_dt; }

public:
	void init();
	int update();
	void render(HDC _dc);
};

