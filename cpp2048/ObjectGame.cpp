#include "framework.h"
#include "ObjectGame.h"
#include "KeyMgr.h"
#include "Texture.h"
#include "PathMgr.h"


CObjectGame::CObjectGame()
	: m_iBoard{}
    , m_iScore(0)
    , m_iMoveCount(0)
    , m_bEnd(false)
    , m_pTileTex(nullptr)
    , m_tLogFont{}
    , m_hFont(nullptr)
    , m_hFont100(nullptr)
    , m_hFont1000(nullptr)
    , m_hOldFont(nullptr)
{
}

CObjectGame::~CObjectGame()
{
    DeleteObject(m_hFont);
    DeleteObject(m_hFont100);
    DeleteObject(m_hFont1000);
}

void CObjectGame::init()
{
    // 최초 숫자 두번 생성
    CreateNum(2);

    if (m_pTex)
    {
        m_vScale.x = (float)m_pTex->GetWidth();
        m_vScale.y = (float)m_pTex->GetHeight();
    }

    initFont();
}

int CObjectGame::update()
{
    if (KEYTAB(KEY_TYPE::KEY_UP))
    {
        ++m_iMoveCount;
        MoveUp();
        CreateNum();
    }        
    else if (KEYTAB(KEY_TYPE::KEY_DOWN))
    {
        ++m_iMoveCount;
        MoveDown();
        CreateNum();
    }        
    else if (KEYTAB(KEY_TYPE::KEY_LEFT))
    {
        ++m_iMoveCount;
        MoveLeft();
        CreateNum();
    }       
    else if (KEYTAB(KEY_TYPE::KEY_RIGHT))
    {
        ++m_iMoveCount;
        MoveRight();
        CreateNum();
    }

    CheckGameOver();
        
	return 0;
}

void CObjectGame::render(HDC _dc)
{
    // board 그리기
    CObject::render(_dc);

    // tile 그리기
    renderTile(_dc);

    // font 그리기
    renderFont(_dc);
}

void CObjectGame::initFont()
{
    wstring strPath = CPathMgr::GetResPath();
    strPath += L"\\Font\\Maplestory.ttf";
    AddFontResource(strPath.c_str());

    m_tLogFont.lfHeight = 60;
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

    m_tLogFont.lfHeight = 50;
    m_hFont100 = CreateFontIndirect(&m_tLogFont);

    m_tLogFont.lfHeight = 40;
    m_hFont1000 = CreateFontIndirect(&m_tLogFont);
}

void CObjectGame::renderTile(HDC _dc)
{
    if (nullptr == m_pTileTex)
        return;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (0 != m_iBoard[i][j])
            {
                BitBlt(_dc
                    , (int)m_vPos.x + 20 + (j * 120), (int)m_vPos.y + 20 + (i * 120) + 80
                    , m_pTileTex->GetWidth(), m_pTileTex->GetHeight(),
                        m_pTileTex->GetDC(), 0, 0, SRCCOPY);
            }
        }
    }
}

void CObjectGame::renderFont(HDC _dc)
{
    m_hOldFont = (HFONT)SelectObject(_dc, m_hFont1000);
    COLORREF hOldTextColor = SetTextColor(_dc, RGB(0, 0, 0));
    COLORREF hOldBackColor = SetBkColor(_dc, RGB(255, 255, 255));

    // Score
    wstring strNum = L"점 수 : " + std::to_wstring(m_iScore);
    TextOut(_dc, (int)m_vPos.x + 20, (int)m_vPos.y + 20, strNum.c_str(), strNum.length());

    // MoveCount
    strNum = L"이 동 : " + std::to_wstring(m_iMoveCount);
    TextOut(_dc, (int)m_vPos.x + 280, (int)m_vPos.y + 20, strNum.c_str(), strNum.length());

    SelectObject(_dc, m_hOldFont);
    SetTextColor(_dc, hOldTextColor);
    SetBkColor(_dc, hOldBackColor);

    // Tile
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (0 != m_iBoard[i][j])
            {
                // 색
                int colorCount = 0;
                int temp = m_iBoard[i][j];
                for (int i = 0; i < 16; ++i)
                {
                    temp >>= 1;
                    if (0 == temp)
                        break;
                    ++colorCount;
                }
                colorCount *= 25;
                if (0 > colorCount)
                    colorCount = 0;
                else if (255 < colorCount)
                    colorCount = 255;

                // 위치
                int fontPosX = 0, fontPosY = 0;
                if (m_iBoard[i][j] >= 1000)
                {
                    m_hOldFont = (HFONT)SelectObject(_dc, m_hFont1000);
                    fontPosX = 5;
                    fontPosY = 30;
                }
                else if (m_iBoard[i][j] >= 100)
                {
                    m_hOldFont = (HFONT)SelectObject(_dc, m_hFont100);
                    fontPosX = 10;
                    fontPosY = 25;
                }
                else if (m_iBoard[i][j] >= 10)
                {
                    m_hOldFont = (HFONT)SelectObject(_dc, m_hFont);
                    fontPosX = 20;
                    fontPosY = 20;
                }
                else
                {
                    m_hOldFont = (HFONT)SelectObject(_dc, m_hFont);
                    fontPosX = 30;
                    fontPosY = 20;
                }
                strNum = std::to_wstring(m_iBoard[i][j]);
                hOldTextColor = SetTextColor(_dc, RGB(0 + colorCount, 0, 0));
                hOldBackColor = SetBkColor(_dc, RGB(153, 217, 234));
                TextOut(_dc, (int)m_vPos.x + 20 + (j * 120) + fontPosX, (int)m_vPos.y + 20 + (i * 120) + 80 + fontPosY, strNum.c_str(), strNum.length());
                SelectObject(_dc, m_hOldFont);
                SetTextColor(_dc, hOldTextColor);
                SetBkColor(_dc, hOldBackColor);
            }
        }
    }
}

void CObjectGame::CreateNum(int count)
{
    // num 반복횟수
    for (int i = 0; i < count; ++i)
    {
        int* p[16] = { nullptr, };
        int emptycount = 0;

        // 2차원 배열 중 비어있는 보드의 주소만 담음
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (0 == m_iBoard[i][j])
                {
                    p[emptycount] = &m_iBoard[i][j];
                    ++emptycount;
                }
            }
        }

        // 90% 확률로 2를, 10% 확률로 4를 선택해
        // 비어있는 보드중 한 곳에 랜덤으로 생성
        if (0 == emptycount)
            return;

        *p[rand() % emptycount] = (rand() % 100 < 90) ? 2 : 4;
    }
}

void CObjectGame::MoveUp()
{
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 1; i <= 3; ++i)
        {
            for (int k = i; k > 0; --k)
            {
                if (m_iBoard[k][j] <= 0)
                    break;
                if (m_iBoard[k - 1][j] != 0 && m_iBoard[k - 1][j] != m_iBoard[k][j])
                    break;

                if (m_iBoard[k - 1][j] == 0)
                {
                    m_iBoard[k - 1][j] = m_iBoard[k][j];
                }
                else if (m_iBoard[k][j] == m_iBoard[k - 1][j])
                {
                    m_iBoard[k - 1][j] *= 2;
                    m_iBoard[k - 1][j] -= (m_iBoard[k - 1][j] * 2);
                    m_iScore += m_iBoard[k][j] * 2;
                }
                m_iBoard[k][j] = 0;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m_iBoard[i][j] < 0)
                m_iBoard[i][j] = abs(m_iBoard[i][j]);
        }
    }
}

void CObjectGame::MoveDown()
{
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 2; i >= 0; --i)
        {
            for (int k = i; k < 3; ++k)
            {
                if (m_iBoard[k][j] <= 0)
                    break;
                if (m_iBoard[k + 1][j] != 0 && m_iBoard[k + 1][j] != m_iBoard[k][j])
                    break;

                if (m_iBoard[k + 1][j] == 0)
                {
                    m_iBoard[k + 1][j] = m_iBoard[k][j];
                }
                else if (m_iBoard[k][j] == m_iBoard[k + 1][j])
                {
                    m_iBoard[k + 1][j] *= 2;
                    m_iBoard[k + 1][j] -= (m_iBoard[k + 1][j] * 2);
                    m_iScore += m_iBoard[k][j] * 2;
                }
                m_iBoard[k][j] = 0;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m_iBoard[i][j] < 0)
                m_iBoard[i][j] = abs(m_iBoard[i][j]);
        }
    }
}

void CObjectGame::MoveLeft()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = j; k > 0; --k)
            {
                if (m_iBoard[i][k] <= 0)
                    break;
                if (m_iBoard[i][k - 1] != 0 && m_iBoard[i][k - 1] != m_iBoard[i][k])
                    break;

                if (m_iBoard[i][k - 1] == 0)
                {
                    m_iBoard[i][k - 1] = m_iBoard[i][k];
                }
                else if (m_iBoard[i][k] == m_iBoard[i][k - 1])
                {
                    m_iBoard[i][k - 1] *= 2;
                    m_iBoard[i][k - 1] -= (m_iBoard[i][k - 1] * 2);
                    m_iScore += m_iBoard[i][k] * 2;
                }
                m_iBoard[i][k] = 0;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m_iBoard[i][j] < 0)
                m_iBoard[i][j] = abs(m_iBoard[i][j]);
        }
    }
}

void CObjectGame::MoveRight()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 2; j >= 0; --j)
        {
            for (int k = j; k < 3; ++k)
            {
                if (m_iBoard[i][k] <= 0)
                    break;
                if (m_iBoard[i][k + 1] != 0 && m_iBoard[i][k + 1] != m_iBoard[i][k])
                    break;

                if (m_iBoard[i][k + 1] == 0)
                {
                    m_iBoard[i][k + 1] = m_iBoard[i][k];
                }
                else if (m_iBoard[i][k] == m_iBoard[i][k + 1])
                {
                    m_iBoard[i][k + 1] *= 2;
                    m_iBoard[i][k + 1] -= (m_iBoard[i][k + 1] * 2);
                    m_iScore += m_iBoard[i][k] * 2;
                }
                m_iBoard[i][k] = 0;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m_iBoard[i][j] < 0)
                m_iBoard[i][j] = abs(m_iBoard[i][j]);
        }
    }
}

void CObjectGame::CheckGameOver()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (m_iBoard[i][j] == 0)
                return;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (m_iBoard[i][j] == m_iBoard[i + 1][j] || m_iBoard[i][j] == m_iBoard[i][j + 1])
                return;

    for (int i = 0; i < 3; ++i)
        if (m_iBoard[i][3] == m_iBoard[i + 1][3])
            return;

    for (int j = 0; j < 3; ++j)
        if (m_iBoard[3][j] == m_iBoard[3][j + 1])
            return;

    m_bEnd = true;
}
