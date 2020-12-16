#pragma once
#include "Object.h"

class CTexture;

class CObjectGame :
    public CObject
{
private:
	// Game
	int m_iBoard[4][4];
	UINT m_iScore;
	UINT m_iMoveCount;
	bool m_bEnd;

	// tile
	CTexture* m_pTileTex;

	// font
	LOGFONT		m_tLogFont;
	HFONT		m_hFont;
	HFONT		m_hFont100;
	HFONT		m_hFont1000;
	HFONT		m_hOldFont;

public:
	virtual void init();
	virtual int update();
	virtual void render(HDC _dc);

private:
	void initFont();
	void renderTile(HDC _dc);
	void renderFont(HDC _dc);

public:
	bool CheckEnd() { return m_bEnd; }
	UINT GetScore() { return m_iScore; }
	UINT GetMoveCount() { return m_iMoveCount; }
	void SetTileTexture(CTexture* _pTex) { m_pTileTex = _pTex; }
	CTexture* GetTileTexture() { return m_pTileTex; }

private:
	void CreateNum(int count = 1);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void CheckGameOver();

public:
	CObjectGame();
	virtual ~CObjectGame();
};

