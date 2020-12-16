#pragma once

class CPathMgr
{
private:
	// 리소스 경로를 저장
	static wchar_t	g_szResPath[255];
	static wchar_t	g_szSavePath[255];


public:
	static void init();
	static wchar_t* GetResPath();
	static wchar_t* GetSavePath();

private:
	CPathMgr() {}
	~CPathMgr() {}
};

