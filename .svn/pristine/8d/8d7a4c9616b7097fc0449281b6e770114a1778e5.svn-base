#include "framework.h"
#include "ObjectRank.h"
#include "PathMgr.h"

CObjectRank::CObjectRank()
	: m_arrRank{}
	, m_bShow(false)
	, m_tLogFont{}
	, m_hFont(nullptr)
	, m_hOldFont(nullptr)
{
}

CObjectRank::~CObjectRank()
{
}

void CObjectRank::init()
{
	LoadRank();
	initFont();
}

void CObjectRank::initFont()
{
	wstring strPath = CPathMgr::GetResPath();
	strPath += L"\\Font\\Maplestory.ttf";
	AddFontResource(strPath.c_str());

	m_tLogFont.lfHeight = 30;
	m_tLogFont.lfWidth = 0;
	m_tLogFont.lfEscapement = 0;
	m_tLogFont.lfOrientation = 0;
	m_tLogFont.lfWeight = 0;
	m_tLogFont.lfItalic = 0;
	m_tLogFont.lfUnderline = 0;
	m_tLogFont.lfStrikeOut = 0;
	m_tLogFont.lfCharSet = HANGEUL_CHARSET;
	m_tLogFont.lfOutPrecision = 0;
	m_tLogFont.lfClipPrecision = 0;
	m_tLogFont.lfQuality = 0;
	m_tLogFont.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
	lstrcpy(m_tLogFont.lfFaceName, TEXT("Maplestory"));

	m_hFont = CreateFontIndirect(&m_tLogFont);
}

void CObjectRank::LoadRank()
{
	// Rank Save 파일 열기
	//const wchar_t* strPath = CPathMgr::GetSavePath();
	//std::wifstream fin;
	//fin.open(strPath, std::ios::in | std::ios::binary);
	//if (!fin)
	//{
	//	MessageBox(CCore::GetInst()->GetMainHWND(), L"File Load Failed", L"Error", MB_OK);
	//	assert(nullptr);
	//}

	FILE* pFile = nullptr;
	_wfopen_s(&pFile, CPathMgr::GetSavePath(), L"rb");
	assert(pFile);

	// Rank 정보 가져오기
	int count = 0; // 저장된 랭크 갯수
	for (int i = 0; i < 10; ++i)
	{
		//if (fin.eof())
		//	break;
		//
		//// 이름
		//Data[i].Name = LoadWString(fin);
		//
		//// 스코어
		//fin.read((wchar_t*)&Data[i].Score, 2);
		//
		//// 움직인 횟수
		//fin.read((wchar_t*)&Data[i].MoveCount, 2);

		m_arrRank[i].Name = LoadWString(pFile);
		fread(&m_arrRank[i].Score, sizeof(int), 1, pFile);
		fread(&m_arrRank[i].MoveCount, sizeof(int), 1, pFile);

		++count;
	}
	fclose(pFile);
	//fin.close();
}

void CObjectRank::SaveRank()
{
	// Rank Save 파일 열기
	//std::wofstream fout;
	//fout.open(strPath, std::ios::out | std::ios::binary);
	//if (!fout)
	//{
	//	MessageBox(CCore::GetInst()->GetMainHWND(), L"File Load Failed", L"Error", MB_OK);
	//	assert(nullptr);
	//}

	FILE* pFile = nullptr;
	_wfopen_s(&pFile, CPathMgr::GetSavePath(), L"wb");
	assert(pFile);

	// Rank 정보 저장하기
	for (int i = 0; i < 10; ++i)
	{
		//// 이름
		//SaveWString(Data[i].Name, fout);
		//
		//// 스코어
		//fout.write((const wchar_t*)(&Data[i].Score), 2);
		//
		//// 움직인 횟수
		//fout.write((const wchar_t*)(&Data[i].MoveCount), 2);

		SaveWString(m_arrRank[i].Name, pFile);
		fwrite(&m_arrRank[i].Score, sizeof(int), 1, pFile);
		fwrite(&m_arrRank[i].MoveCount, sizeof(int), 1, pFile);
	}
	fclose(pFile);
	//fout.close();
}

void CObjectRank::AddRank(RankData _tData)
{
	// 점수 비교해 내 랭킹 구하기
	int Ranking = -1;
	for (int i = 0; i < 10; ++i)
	{
		if (_tData.Score > m_arrRank[i].Score)
		{
			Ranking = i;
			break;
		}
		else if (_tData.Score == m_arrRank[i].Score)
		{
			if (_tData.MoveCount > m_arrRank[i].MoveCount)
			{
				Ranking = i;
				break;
			}
		}
	}

	// 순위권에 들지 못함
	if (0 > Ranking || 10 <= Ranking)
		return;

	// 내 점수 데이터에 추가
	RankData temp = m_arrRank[Ranking];
	m_arrRank[Ranking] = _tData;
	for (int i = Ranking + 1; i < 10; ++i)
	{
		RankData temp2 = m_arrRank[i];
		m_arrRank[i] = temp;
		temp = temp2;
	}

	// 갱신 된 랭킹 정보 저장
	SaveRank();
}

int CObjectRank::update()
{
	return 0;
}

void CObjectRank::render(HDC _dc)
{
	if (!m_bShow)
		return;

	// Board Texture
	CObject::render(_dc);
	renderFont(_dc);
}

void CObjectRank::renderFont(HDC _dc)
{
	m_hOldFont = (HFONT)SelectObject(_dc, m_hFont);
	COLORREF hOldTextColor = SetTextColor(_dc, RGB(255, 174, 201));
	COLORREF hOldBackColor = SetBkColor(_dc, RGB(16, 70, 38));

	wstring strNum = L"순위";
	TextOut(_dc, (int)m_vPos.x + 50, (int)m_vPos.y + 40, strNum.c_str(), strNum.length());

	strNum = L"이름";
	TextOut(_dc, (int)m_vPos.x + 180, (int)m_vPos.y + 40, strNum.c_str(), strNum.length());

	strNum = L"점수";
	TextOut(_dc, (int)m_vPos.x + 300, (int)m_vPos.y + 40, strNum.c_str(), strNum.length());

	strNum = L"이동";
	TextOut(_dc, (int)m_vPos.x + 405, (int)m_vPos.y + 40, strNum.c_str(), strNum.length());

	SelectObject(_dc, m_hOldFont);
	SetTextColor(_dc, hOldTextColor);
	SetBkColor(_dc, hOldBackColor);

	m_hOldFont = (HFONT)SelectObject(_dc, m_hFont);
	hOldTextColor = SetTextColor(_dc, RGB(255, 255, 255));
	hOldBackColor = SetBkColor(_dc, RGB(16, 70, 38));
	// Ranking Font
	for (int i = 0; i < 10; ++i)
	{
		int iHeight = i * 45;

		// 순위
		strNum = std::to_wstring(i + 1);
		TextOut(_dc, (int)m_vPos.x + 50, (int)m_vPos.y + 100 + iHeight, strNum.c_str(), strNum.length());

		// 이름
		TextOut(_dc, (int)m_vPos.x + 130, (int)m_vPos.y + 100 + iHeight, m_arrRank[i].Name.c_str(), m_arrRank[i].Name.length());

		// Score
		strNum = std::to_wstring(m_arrRank[i].Score);
		TextOut(_dc, (int)m_vPos.x + 290, (int)m_vPos.y + 100 + iHeight, strNum.c_str(), strNum.length());

		// MoveCount
		strNum = std::to_wstring(m_arrRank[i].MoveCount);
		TextOut(_dc, (int)m_vPos.x + 400, (int)m_vPos.y + 100 + iHeight, strNum.c_str(), strNum.length());
	}
	SelectObject(_dc, m_hOldFont);
	SetTextColor(_dc, hOldTextColor);
	SetBkColor(_dc, hOldBackColor);
}