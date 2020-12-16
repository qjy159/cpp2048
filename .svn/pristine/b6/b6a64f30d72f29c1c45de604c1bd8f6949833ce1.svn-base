#include "framework.h"
#include "Object.h"
#include "Texture.h"
#include "Camera.h"

CObject::CObject()
	: m_pTex(nullptr)
{
}

CObject::~CObject()
{
}

void CObject::render(HDC _dc)
{
	if (nullptr != m_pTex)
	{
		// 현재 오브젝트의 위치를 카메라 기준에서의 원점으로 이동시킨 위치로 변경
		//Vec2 vCamPos = CCamera::GetInst()->GetCamSpacePos(m_vPos);

		// 카메라 기준 원점으로 MemDC에 그린다.
		//BitBlt(_dc
		//	, (int)vCamPos.x, (int)vCamPos.y
		//	, m_pTex->GetWidth(), m_pTex->GetHeight(),
		//	m_pTex->GetDC(), 0, 0, SRCCOPY);
	}
}
