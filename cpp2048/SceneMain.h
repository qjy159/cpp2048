#pragma once
#include "Scene.h"

class CObjectGame;
class CObjectRank;

class CSceneMain :
    public CScene
{
private:
    CObjectGame* m_pGame;
    CObjectRank* m_pRank;
    wstring      m_strSaveName;
    bool         m_bSave;

public:
    virtual void Enter();
    virtual void Exit();

public:
    virtual int update();
    virtual void render(HDC _dc);

public:
    void SetSaveName(wstring strName) { m_strSaveName = strName; }

public:
    CSceneMain();
    virtual ~CSceneMain();
};

