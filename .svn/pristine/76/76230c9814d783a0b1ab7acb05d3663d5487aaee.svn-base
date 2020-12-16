#pragma once

class CTexture
{
private:
    wstring		m_strKey;
    HBITMAP     m_hBit;
    HDC         m_dc;
    UINT        m_iWidth;
    UINT        m_iHeight;

public:
    UINT GetWidth() { return m_iWidth; }
    UINT GetHeight() { return m_iHeight; }
    HDC GetDC() { return m_dc; }
    wstring& GetKey() { return m_strKey; }
    void SetKey(const wstring& _strKey) { m_strKey = _strKey; }

public:
    // 경로를 통해 실제 이미지를 로드
    static CTexture* Load(const wstring& _strFullPath);
    // 넘겨준 크기만큼 memory texture 생성
    static CTexture* Load(UINT _iWidth, UINT _iHeight);

public:
    CTexture();
    virtual ~CTexture();
};