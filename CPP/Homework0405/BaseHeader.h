#pragma once

#include <Windows.h>
#include <assert.h>
//
//void MessageBoxAssert(const char* _Text)
//{
//	MessageBoxA(nullptr, _Text, "Error", MB_OK);
//	assert(false);
//}

#define MessageBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK);	assert(false);