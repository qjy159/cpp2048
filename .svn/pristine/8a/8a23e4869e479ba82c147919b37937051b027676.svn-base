#include "framework.h"
#include "TexMgr.h"
#include "PathMgr.h"

CTexMgr::CTexMgr()
{
}

CTexMgr::~CTexMgr()
{
	Safe_Delete_Map(m_mapTex);
}

CTexture* CTexMgr::CreateTexture(const wstring& _strKey, UINT _iWidth, UINT _iHgith)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);
	if (iter != m_mapTex.end())
		return iter->second;

	CTexture* pTex = CTexture::Load(_iWidth, _iHgith);

	if (NULL == pTex)
		return NULL;

	pTex->SetKey(_strKey);
	m_mapTex.insert(make_pair(_strKey, pTex));
	return pTex;
}

CTexture* CTexMgr::Load(const wstring& _strKey, const wstring& _strPath)
{
	wstring strPath = CPathMgr::GetResPath();
	strPath += _strPath;

	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);
	if (iter != m_mapTex.end())
		return iter->second;

	CTexture* pTex = CTexture::Load(strPath);
	if (NULL == pTex)
		return NULL;

	pTex->SetKey(_strKey);
	m_mapTex.insert(make_pair(_strKey, pTex));
	return pTex;
}
