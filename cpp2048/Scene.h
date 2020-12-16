#pragma once

class CObject;

class CScene
{
private:
	// render 순서를 정해주기 위해 
	// Scene
	// ㄴ Layer(BackGround -> Object -> UI 순서)
	//    ㄴ Object
	vector<vector<CObject*>>	m_vecObj;
	SCENE_TYPE					m_eType;

public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	void SetSceneType(SCENE_TYPE _eType) { m_eType = _eType; }
	SCENE_TYPE GetSceneType() { return m_eType; }

public:
	void AddObject(CObject* _pObj, OBJ_LAYER _eLayer);
	void DeleteObject(CObject* _pObj);
	void ClearObject(OBJ_LAYER _eLayer = OBJ_LAYER::END);

public:
	virtual int update();
	virtual void render(HDC _dc);

protected:
	CScene();
public:
	virtual ~CScene();
};

