#pragma once

#include "framework.h"

template <typename T, int iSize>
void Safe_Delete_Array(T* (&_pArr)[iSize])
{
	for_each(_pArr[0], _pArr[iSize - 1], [](auto pData) { SAFE_DELETE(pData); });
}

template<typename T>
void Safe_Delete_Vec(vector<T> _vec)
{
	for_each(_vec.begin(), _vec.end(), [](auto pData) { SAFE_DELETE(pData); });
}

template<typename T>
void Safe_Delete_list(list<T> _list)
{
	for_each(_list.begin(), _list.end(), [](auto pData) { SAFE_DELETE(pData); });
}

template<typename T1, typename T2>
void Safe_Delete_Map(map<T1, T2> _map)
{
	for_each(_map.begin(), _map.end(), [](auto pair) { SAFE_DELETE(pair.second); });
}

// 0 ~ 1 사이의 랜덤 float 값
float randF();

// a ~ b 사이의 랜덤 float 값
float randF(float a, float b);