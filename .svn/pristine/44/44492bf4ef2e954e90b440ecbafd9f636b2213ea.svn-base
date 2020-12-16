#include "framework.h"
#include "SceneMgr.h"
#include "Scene.h"

CSceneMgr::CSceneMgr()
{
}

CSceneMgr::~CSceneMgr()
{
}

void CSceneMgr::ChangeScene(SCENE_TYPE _eType)
{
}

void CSceneMgr::init()
{
	// ¾À »ı¼º
}

int CSceneMgr::update()
{
	if (nullptr != m_pCurScene)
		m_pCurScene->update();

	return 0;
}

void CSceneMgr::render(HDC _dc)
{
	if (nullptr != m_pCurScene)
		m_pCurScene->render(_dc);
}
