#pragma once
#include "Scene.h"

enum class BTN_TYPE
{
    START = 0,
    RANK = 1,
    EXIT = 2,
    END
};

class CObjectImage;

class CSceneStart :
    public CScene
{
private:
    CObjectImage* m_arrButton[(UINT)BTN_TYPE::END];
    BTN_TYPE m_eBtnType;

public:
    virtual void Enter();
    virtual void Exit();

public:
    virtual int update();
    virtual void render(HDC _dc);

public:
    CSceneStart();
    virtual ~CSceneStart();
};

