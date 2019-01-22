
#include "mclauth.h"
#include "mclsdkdelegate.h"

using namespace AuthSdk;

MclAuth::MclAuth() : m_delegate(nullptr)
{
}


MclAuth::~MclAuth()
{
}

void MclAuth::SetDelegate(AuthSdk::MclSdkDelegate* del)
{
	m_delegate = del;
}

MclSdkDelegate* MclAuth::GetDelegate()
{
	return m_delegate;
}

void MclAuth::Login(unsigned int uid, const char* ip, int port)
{
	m_delegate->OnLoginFinish(1);
}
