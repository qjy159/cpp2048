#include "framework.h"
#include "Scene.h"
#include "Object.h"
#include "SceneMgr.h"



CScene::CScene()
{
	// 레이어 갯수만큼 확장시켜서, vector<CObj*> 타입 백터를 확보해둔다.
	m_vecObj.resize((UINT)OBJ_LAYER::END);
}

CScene::~CScene()
{
}

void CScene::AddObject(CObject* _pObj, OBJ_LAYER _eLayer)
{
	//_pObj->SetLayer(_eLayer);
	//m_vecObj[(UINT)_eLayer].push_back(_pObj);
}	

void CScene::DeleteObject(CObject* _pObj)
{
	//OBJ_LAYER eLayer = _pObj->GetLayer();
	//auto iter = m_vecObj[(UINT)eLayer].begin();
	//for (; iter != m_vecObj[(UINT)eLayer].end(); ++iter)
	//{
	//	if (_pObj == *iter)
	//	{
	//		m_vecObj[(UINT)eLayer].erase(iter);
	//		delete _pObj;
	//		return;
	//	}
	//}
}

void CScene::ClearObject(OBJ_LAYER _eLayer)
{
	// 전체 오브젝트를 삭제한다.
	if (OBJ_LAYER::END == _eLayer)
	{
		for (UINT i = 0; i < m_vecObj.size(); ++i)
		{
			for (UINT j = 0; j < m_vecObj[i].size(); ++j)
			{
				delete m_vecObj[i][j];
			}
			m_vecObj[i].clear();
		}
		return;
	}
	// 지정한 그룹 오브젝트들만 삭제한다.
	for (UINT i = 0; i < m_vecObj[(UINT)_eLayer].size(); ++i)
	{
		delete m_vecObj[(UINT)_eLayer][i];
	}
	m_vecObj[(UINT)_eLayer].clear();
}

int CScene::update()
{
	for (UINT i = 0; i < m_vecObj.size(); ++i)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->update();
		}
	}

	return 0;
}

void CScene::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)m_vecObj.size(); ++i)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->render(_dc);
		}
	}
}