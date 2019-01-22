#pragma once
#include "imclauth.h"

using namespace AuthSdk;

#define NATIVE_API __declspec(dllexport)

extern "C"
{
	NATIVE_API IMclAuth* GetInstance();
}