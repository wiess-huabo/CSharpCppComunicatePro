#pragma once
#include "mclsdkdelegate.h"

namespace AuthSdk
{
	class IMclAuth
	{
	public:
		virtual void SetDelegate(MclSdkDelegate* delegate) = 0;
		virtual MclSdkDelegate* GetDelegate(void) = 0;
		virtual void Login(unsigned int uid, const char* ip, int port) = 0;
	};
}
