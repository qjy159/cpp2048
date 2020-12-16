#pragma once

#include "Texture.h"

class CTexMgr
{
	SINGLE(CTexMgr);

private:
	map<wstring, CTexture*>	m_mapTex;

public:
	CTexture* CreateTexture(const wstring& _strKey, UINT _iWidth, UINT _iHgith);
	CTexture* Load(const wstring& _strKey, const wstring& _strPath = L"");
};

