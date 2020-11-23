#include "framework.h"
#include "Texture.h"
#include "Core.h"

CTexture::CTexture()
{
}

CTexture::~CTexture()
{
	DeleteObject(m_hBit);
	DeleteObject(m_dc);
}

CTexture* CTexture::Load(const wstring& _strFullPath)
{
	HBITMAP hBit = (HBITMAP)LoadImage(NULL, _strFullPath.c_str(), IMAGE_BITMAP, 0, 0,
		LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	HDC dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	if (NULL == hBit || NULL == dc)
		assert(NULL);

	HBITMAP oldBit = (HBITMAP)SelectObject(dc, hBit);
	DeleteObject(oldBit);

	BITMAP bm{};
	GetObject(hBit, sizeof(BITMAP), &bm);

	CTexture* pTexture = new CTexture;
	pTexture->m_hBit = hBit;
	pTexture->m_dc = dc;
	pTexture->m_iWidth = bm.bmWidth;
	pTexture->m_iHeight = bm.bmHeight;

	return pTexture;
}

CTexture* CTexture::Load(UINT _iWidth, UINT _iHeight)
{
	HBITMAP hBit = CreateCompatibleBitmap(CCore::GetInst()->GetMainDC(), _iWidth, _iHeight);
	HDC dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	if (NULL == hBit || NULL == dc)
		return NULL;

	HBITMAP oldBit = (HBITMAP)SelectObject(dc, hBit);
	DeleteObject(oldBit);

	CTexture* pTexture = new CTexture;
	pTexture->m_hBit = hBit;
	pTexture->m_dc = dc;
	pTexture->m_iWidth = _iWidth;
	pTexture->m_iHeight = _iHeight;

	return pTexture;
}