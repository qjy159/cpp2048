#pragma once
#include "Texture.h"

class CCore
{
	SINGLE(CCore);

private:
	HWND		m_hWnd;			// ������ �ڵ�
	HDC			m_hDC;			// ������ DC
	CTexture*	m_pMemTex;		// ������۸��� ���� �ؽ���(�޸� DC)
	Vec2		m_vResolution;	// �ػ�
	bool		m_bFocus;		// �����쿡 ��Ŀ���� ���������� Ȯ��

public:
	// �ʱ�ȭ
	void init(HWND _hWnd);
	// main �Լ����� ���α׷� ȣ��
	UINT progress();
	// �ػ� ����
	void ChangeWindowSize(UINT _iLeft, UINT _iTop, UINT _iWidth, UINT _iHeight, bool _bHasMenu = false);
	// ������ �̸� ����
	void ChangeWindowTitle(wstring strTitle);

private:
	// Core ������Ʈ���� ���� ��� Ŭ������ ��ȸ�ϸ� 1�����Ӹ��� ȣ���ϴ� �Լ���
	// update�� 1������ ��ȭ���� ����ϰ�
	// render�� �ڽ��� memDC�� �׷��ش�.
	int update();
	void render();

public:
	HWND GetMainHWND() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	HDC GetMemDC() { return m_pMemTex->GetDC(); }
	Vec2 GetResolution() { return m_vResolution; }
	bool GetWndFocus() { return m_bFocus; }
};

