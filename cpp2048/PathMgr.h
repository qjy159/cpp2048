#pragma once

class CPathMgr
{
private:
	// 리소스 경로를 저장
	static wchar_t	g_szResPath[255];

public:
	static void init();
	static wchar_t* GetResPath();

private:
	CPathMgr() {}
	~CPathMgr() {}
};

