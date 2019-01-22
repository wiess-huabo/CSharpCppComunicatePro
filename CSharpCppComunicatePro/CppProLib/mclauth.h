#pragma once
#include "mclsdkdelegate.h"
#include "imclauth.h"

namespace AuthSdk
{
	class AuthSocket;
	class GameControlSocket;
	class NetDispatcher;
	class MclAuth : public IMclAuth
	{
	public:
		MclAuth();
		~MclAuth();

		void SetDelegate(MclSdkDelegate* delegate) override;
		MclSdkDelegate* GetDelegate(void) override;
		void Login(unsigned int uid, const char* ip, int port) override;

	private:
		MclSdkDelegate* m_delegate;
	};
}