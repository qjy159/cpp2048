#pragma once
#include "Object.h"
class CObjectImage :
    public CObject
{
private:
	bool		m_bBorderLine;

public:
	virtual int update();
	virtual void render(HDC _dc);

public:
	void BorderLine(bool _bLine) { m_bBorderLine = _bLine; }

public:
	CObjectImage();
	virtual ~CObjectImage();
};

