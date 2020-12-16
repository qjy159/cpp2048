#include "framework.h"
#include "SceneRank.h"
#include "ObjectImage.h"
#include "TexMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ObjectRank.h"

CSceneRank::CSceneRank()
{
}

CSceneRank::~CSceneRank()
{
}

void CSceneRank::Enter()
{
	// Background (Default Position x = 0 , y = 0)
	CObjectImage* ObjImage = new CObjectImage;
	ObjImage->SetLayer(OBJ_LAYER::BACKGROUND);
	ObjImage->SetTexture(CTexMgr::GetInst()->Load(L"Background", L"Texture\\Background.bmp"));
	AddObject(ObjImage, OBJ_LAYER::BACKGROUND);

	//Ranking
	CObjectRank* ObjRank = new CObjectRank;
	ObjRank->SetLayer(OBJ_LAYER::UI);
	ObjRank->SetTexture(CTexMgr::GetInst()->Load(L"RankBoard", L"Texture\\RankBoard.bmp"));
	ObjRank->SetPos(Vec2(390.f, 110.f));
	ObjRank->init();
	ObjRank->ShowRank(true);
	AddObject(ObjRank, OBJ_LAYER::UI);
}

void CSceneRank::Exit()
{
	ClearObject();
}

int CSceneRank::update()
{
	CScene::update();

	if(KEYTAB(KEY_TYPE::KEY_ESC))
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::START);

	return 0;
}

void CSceneRank::render(HDC _dc)
{
	CScene::render(_dc);
}