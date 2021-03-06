#include "framework.h"
#include "Object.h"
#include "Texture.h"

CObject::CObject()
	: m_pTex(nullptr)
	, m_eLayer(OBJ_LAYER::END)
{
}

CObject::~CObject()
{
}

void CObject::render(HDC _dc)
{
	if (nullptr != m_pTex)
	{
		BitBlt(_dc
			, (int)m_vPos.x, (int)m_vPos.y
			, m_pTex->GetWidth(), m_pTex->GetHeight(),
			m_pTex->GetDC(), 0, 0, SRCCOPY);
	}
}
