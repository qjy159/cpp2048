#pragma once
#include "Object.h"

struct RankData
{
	wstring Name;
	UINT Score;
	UINT MoveCount;

	RankData()
		: Score(0)
		, MoveCount(0)
	{}
};

class CObjectRank :
    public CObject
{
	// Data
	RankData m_arrRank[10];
	bool	 m_bShow;

	// Font
	LOGFONT		m_tLogFont;
	HFONT		m_hFont;
	HFONT		m_hOldFont;

public:
	virtual void init();
	virtual int update();
	virtual void render(HDC _dc);

private:
	void initFont();
	void renderFont(HDC _dc);

public:
	void LoadRank();
	void SaveRank();
	void AddRank(RankData _tData);
	void ShowRank(bool _bShow) { m_bShow = _bShow; }

public:
	CObjectRank();
	virtual ~CObjectRank();
};

