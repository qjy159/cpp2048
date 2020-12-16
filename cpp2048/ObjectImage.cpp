#include "framework.h"
#include "ObjectImage.h"
#include "Texture.h"

CObjectImage::CObjectImage()
	: m_bBorderLine(false)
{
}

CObjectImage::~CObjectImage()
{
}

int CObjectImage::update()
{
	return 0;
}

void CObjectImage::render(HDC _dc)
{
	CObject::render(_dc);

	if (m_bBorderLine)
	{
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 100));
		HPEN hOldPen = (HPEN)SelectObject(_dc, hPen);

		MoveToEx(_dc, (int)m_vPos.x, (int)m_vPos.y, NULL);
		LineTo(_dc, (int)(m_vPos.x + m_pTex->GetWidth()), (int)(m_vPos.y));
		LineTo(_dc, (int)(m_vPos.x + m_pTex->GetWidth()), (int)(m_vPos.y + m_pTex->GetHeight()));
		LineTo(_dc, (int)(m_vPos.x), (int)(m_vPos.y + m_pTex->GetHeight()));
		LineTo(_dc, (int)(m_vPos.x), (int)(m_vPos.y));

		SelectObject(_dc, hOldPen);
		DeleteObject(hPen);
	}
}