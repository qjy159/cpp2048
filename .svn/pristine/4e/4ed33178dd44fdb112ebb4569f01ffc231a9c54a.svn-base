#pragma once
#include "Texture.h"

class CCore
{
	SINGLE(CCore);

private:
	HWND		m_hWnd;			// 윈도우 핸들
	HDC			m_hDC;			// 윈도우 DC
	CTexture*	m_pMemTex;		// 더블버퍼링을 위한 텍스쳐(메모리 DC)
	Vec2		m_vResolution;	// 해상도
	bool		m_bFocus;		// 윈도우에 포커스가 맞춰졌는지 확인

public:
	// 초기화
	void init(HWND _hWnd);
	// main 함수에서 프로그램 호출
	UINT progress();
	// 해상도 변경
	void ChangeWindowSize(UINT _iLeft, UINT _iTop, UINT _iWidth, UINT _iHeight, bool _bHasMenu = false);
	// 윈도우 이름 변경
	void ChangeWindowTitle(wstring strTitle);

private:
	// Core 업데이트부터 하위 모든 클래스를 순회하며 1프레임마다 호출하는 함수들
	// update는 1프레임 변화량을 계산하고
	// render는 자신을 memDC에 그려준다.
	int update();
	void render();

public:
	HWND GetMainHWND() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	HDC GetMemDC() { return m_pMemTex->GetDC(); }
	Vec2 GetResolution() { return m_vResolution; }
	bool GetWndFocus() { return m_bFocus; }
};

