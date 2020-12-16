#include "framework.h"
#include "SceneMain.h"
#include "ObjectImage.h"
#include "TexMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "ObjectGame.h"
#include "Core.h"
#include "resource.h"
#include "ObjectRank.h"


CSceneMain::CSceneMain()
	: m_pGame(nullptr)
	, m_pRank(nullptr)
	, m_bSave(false)
{
}

CSceneMain::~CSceneMain()
{
}

void CSceneMain::Enter()
{
	// Background (Default Position x = 0 , y = 0)
	CObjectImage* ObjImage = new CObjectImage;
	ObjImage->SetLayer(OBJ_LAYER::BACKGROUND);
	ObjImage->SetTexture(CTexMgr::GetInst()->Load(L"Background", L"Texture\\Background.bmp"));
	AddObject(ObjImage, OBJ_LAYER::BACKGROUND);

	// 2048 Game
	m_pGame = new CObjectGame;
	m_pGame->SetLayer(OBJ_LAYER::MAIN);
	m_pGame->SetTexture(CTexMgr::GetInst()->Load(L"Board", L"Texture\\Board.bmp")); // board 배경
	m_pGame->SetTileTexture(CTexMgr::GetInst()->Load(L"Tile", L"Texture\\Tile.bmp")); // tile 
	m_pGame->SetPos(Vec2(390.f, 110.f));
	m_pGame->init();
	AddObject(m_pGame, OBJ_LAYER::MAIN);

	// Ranking Data
	m_pRank = new CObjectRank;
	m_pRank->SetLayer(OBJ_LAYER::UI);
	m_pRank->init();
	m_pRank->ShowRank(false);
	AddObject(m_pRank, OBJ_LAYER::UI);
}

void CSceneMain::Exit()
{
	ClearObject();
}

int CSceneMain::update()
{
	CScene::update();

	if (m_pGame->CheckEnd())
	{
		if (!m_bSave)
		{
			// 저장할 이름 입력 받기
			SendMessage(CCore::GetInst()->GetMainHWND(), WM_COMMAND, IDD_GAMEEND, 0);
			m_bSave = true;
		}
		else
		{
			if (0 != m_strSaveName.size())
			{
				RankData myRank;
				myRank.Name = m_strSaveName;
				myRank.Score = m_pGame->GetScore();
				myRank.MoveCount = m_pGame->GetMoveCount();
				
				m_pRank->AddRank(myRank);
			}
			// Rank Scene 전환
			CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::RANK);
			m_strSaveName = L"";
			m_bSave = false;
		}
	}

	if (KEYTAB(KEY_TYPE::KEY_ESC))
		CSceneMgr::GetInst()->ChangeScene(SCENE_TYPE::START);

	return 0;
}

void CSceneMain::render(HDC _dc)
{
	CScene::render(_dc);
}

INT_PTR CALLBACK RankName(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, LOWORD(wParam));

			// 저장할 이름 입력 받아오기
			wchar_t inputName[100];
			GetDlgItemText(hDlg, IDC_EDIT1, inputName, 100);
			if (nullptr != inputName)
				((CSceneMain*)CSceneMgr::GetInst()->GetCurScene())->SetSaveName(inputName);

			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDCANCEL2)
		{
			EndDialog(hDlg, LOWORD(wParam));
		}
		break;
	}
	return (INT_PTR)FALSE;
}