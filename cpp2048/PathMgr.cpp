#include "PathMgr.h"
#include "framework.h"

wchar_t CPathMgr::g_szResPath[255] = L"";
wchar_t CPathMgr::g_szSavePath[255] = L"";

void CPathMgr::init()
{
	// 현재 프로세스의 경로를 받는다.
	GetCurrentDirectory(255, g_szResPath);

	// 솔루션 폴더경로까지 지우기
	for (UINT i = wcslen(g_szResPath) - 1; i > 0; --i)
	{
		if ('\\' == g_szResPath[i])
		{
			g_szResPath[i + 1] = 0;
			break;
		}
	}
	
	// 리소스 폴더경로 추가
	// -> bin -> Resources
	wcscat_s(g_szResPath, L"bin\\Resources\\");

	// 현재 프로세스의 경로를 받는다.
	GetCurrentDirectory(255, g_szSavePath);

	// 솔루션 폴더경로까지 지우기
	for (UINT i = wcslen(g_szSavePath) - 1; i > 0; --i)
	{
		if ('\\' == g_szSavePath[i])
		{
			g_szSavePath[i + 1] = 0;
			break;
		}
	}

	// 리소스 폴더경로 추가
	// -> bin -> Resources
	wcscat_s(g_szSavePath, L"bin\\Resources\\Save\\RankSave.data");
}

wchar_t* CPathMgr::GetResPath()
{
	return g_szResPath;
}

wchar_t* CPathMgr::GetSavePath()
{
	return g_szSavePath;
}
