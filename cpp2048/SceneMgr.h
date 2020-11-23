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

public:
	void init();
	int update();
	void render(HDC _dc);
};

