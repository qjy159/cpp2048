#pragma once
#include "Scene.h"
class CSceneRank :
    public CScene
{
public:
    virtual void Enter();
    virtual void Exit();

public:
    virtual int update();
    virtual void render(HDC _dc);

public:
    CSceneRank();
    virtual ~CSceneRank();
};

