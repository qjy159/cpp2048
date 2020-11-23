#pragma once

struct tKey
{
	KEY_TYPE	eType;
	KEY_STATE	eState;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);

private:
	vector<tKey>	m_vecKey;

public:
	void init();
	void update();

public:
	// Key 입력 확인은 define.h 참고
	bool GetKeyState(KEY_TYPE _eType, KEY_STATE _eState)
	{
		if (_eState == m_vecKey[(UINT)_eType].eState)
			return true;
		return false;
	}
};

