#include "func.h"

float randF()
{
	return (float)(rand()) / (float)RAND_MAX;
}

float randF(float a, float b)
{
	return a + randF() * (b - a);
}

void SaveWString(const wstring& _str, FILE* _pFile)
{
	assert(!(255 < _str.length()));

	BYTE len = (BYTE)_str.length();
	fwrite(&len, sizeof(BYTE), 1, _pFile);
	fwrite(_str.c_str(), sizeof(wchar_t), len, _pFile);
}

wchar_t* LoadWString(FILE* _pFile)
{
	static wchar_t szBuff[255] = {};

	wmemset(szBuff, 0, 255);

	BYTE len = 0;
	fread(&len, sizeof(BYTE), 1, _pFile);
	fread(szBuff, sizeof(wchar_t), len, _pFile);
	return szBuff;
}

void SaveWString(const wstring& _str, std::wofstream& fout)
{
	assert(!(255 < _str.length()));
	WORD len = (WORD)_str.length();
	fout.write((const wchar_t*)(&len), 1);
	fout.write(_str.c_str(), len);
}

wchar_t* LoadWString(std::wifstream& fin)
{
	static wchar_t szBuff[255] = {};
	wmemset(szBuff, 0, 255);
	WORD len = 0;
	fin.read((wchar_t*)(&len), 1);
	fin.read(szBuff, len);
	return szBuff;
}