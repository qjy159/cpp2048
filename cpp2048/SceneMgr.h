#pragma once

class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);

private:
	CScene*		m_arrScene[(UINT)SCENE_TYPE::END];
	CScene*		m_pCurScene;

public:
	void ChangeScene(SCENE_TYPE _eType);
	CScene* GetCurScene() { return m_pCurScene; }

public:
	void init();
	int update();
	void render(HDC _dc);
};

