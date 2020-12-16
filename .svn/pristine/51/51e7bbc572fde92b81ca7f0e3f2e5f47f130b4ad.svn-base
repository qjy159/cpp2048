#include "framework.h"
#include "SceneStart.h"        
#include "TexMgr.h"
#include "Texture.h"
#include "PathMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ObjectImage.h"
#include "Core.h"

CSceneStart::CSceneStart()
	: m_arrButton{}
	, m_eBtnType(BTN_TYPE::START)
{
}

CSceneStart::~CSceneStart()
{
}

void CSceneStart::Enter()
{
	// Background (Default Position x = 0 , y = 0)
	CObjectImage* ObjImage = new CObjectImage;
	ObjImage->SetLayer(OBJ_LAYER::BACKGROUND);
	ObjImage->SetTexture(CTexMgr::GetInst()->Load(L"BackgroundStart", L"Texture\\BackgroundStart.bmp"));
	AddObject(ObjImage, OBJ_LAYER::BACKGROUND);

	// Start Button
	m_arrButton[(UINT)BTN_TYPE::START] = new CObjectImage;
	m_arrButton[(UINT)BTN_TYPE::START]->SetLayer(OBJ_LAYER::UI);
	m_arrButton[(UINT)BTN_TYPE::START]->SetTexture(CTexMgr::GetInst()->Load(L"ButtonStart", L"Texture\\ButtonStart.bmp"));
	m_arrButton[(UINT)BTN_TYPE::START]->SetPos(Vec2(540.f, 350.f));
	m_arrButton[(UINT)BTN_TYPE::START]->BorderLine(true);
	AddObject(m_arrButton[(UINT)BTN_TYPE::START], OBJ_LAYER::UI);

	// Rank Button
	m_arrButton[(UINT)BTN_TYPE::RANK] = new CObjectImage;
	m_arrButton[(UINT)BTN_TYPE::RANK]->SetLayer(OBJ_LAYER::UI);
	m_arrButton[(UINT)BTN_TYPE::RANK]->SetTexture(CTexMgr::GetInst()->Load(L"ButtonRank", L"Texture\\ButtonRank.bmp"));
	m_arrButton[(UINT)BTN_TYPE::RANK]->SetPos(Vec2(540.f, 500.f));
	AddObject(m_arrButton[(UINT)BTN_TYPE::RANK], OBJ_LAYER::UI);

	// Exit Button
	m_arrButton[(UINT)BTN_TYPE::EXIT] = new CObjectImage;
	m_arrButton[(UINT)BTN_TYPE::EXIT]->SetLayer(OBJ_LAYER::UI);
	m_arrButton[(UINT)BTN_TYPE::EXIT]->SetTexture(CTexMgr::GetInst()->Load(L"Button", L"Texture\\ButtonExit.bmp"));
	m_arrButton[(UINT)BTN_TYPE::EXIT]->SetPos(Vec2(540.f, 650.f));
	AddObject(m_arrButton[(UINT)BTN_TYPE::EXIT], OBJ_LAYER::UI);

	m_eBtnType = BTN_TYPE::START;
}

void CSceneStart::Exit()
{
	ClearObject();
}

int CSceneStart::update()
{
	CScene::update();

	// 버튼 고르기
	if (KEYTAB(KEY_TYPE::KEY_UP))
	{
		m_arrButton[(UINT)m_eBtnType]->BorderLine(false);
		int index = (UINT)m_eBtnType - 1;
		if (0 > index)
			index = 2;
		m_eBtnType = (BTN_TYPE)index;
		m_arrButton[(UINT)m_eBtnType]->BorderLine(true);
	}
	if (KEYTAB(KEY_TYPE::KEY_DOWN))
	{
		m_arrButton[(UINT)m_eBtnType]->BorderLine(false);
		int index = (UINT)m_eBtnType + 1;
		if (2 < index)
			index = 0;
		m_eBtnType = (BTN_TYPE)index;
		m_arrButton[(UINT)m_eBtnType]->BorderLine(true);
	}


	// 버튼 선택
	if (KEYTAB(KEY_TYPE::KEY_ENTER) || KEYTAB(KEY_TYPE::KEY_SPACE))
	{
		switch (m_eBtnType)
		{
		case BTN_TYPE::START:
			CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::MAIN);
			break;
		case BTN_TYPE::RANK:
			CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::RANK);
			break;
		case BTN_TYPE::EXIT:
			DestroyWindow(CCore::GetInst()->GetMainHWND());
			break;
		}
	}
		

	return 0;
}

void CSceneStart::render(HDC _dc)
{
	CScene::render(_dc);
}