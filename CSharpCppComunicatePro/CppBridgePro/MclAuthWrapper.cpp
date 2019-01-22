#include <windows.h>
#include <msclr/marshal.h>

#include "MclAuthWrapper.h"
using namespace ::AuthSdkWrapper;


MclAuthWrapper::MclAuthWrapper()
{
	HINSTANCE hGetProcIDDLL = LoadLibraryA("./CppProLib.dll");
	if (hGetProcIDDLL)
	{
		typedef AuthSdk::IMclAuth* (*GET_INST_FUNC_PTR)(const char*);
		GET_INST_FUNC_PTR pCreatFunc = (GET_INST_FUNC_PTR)GetProcAddress(hGetProcIDDLL, "GetInstance");
		if (pCreatFunc)
		{
			m_sdk = (*pCreatFunc)(NULL);
			m_delegate = new DelegateWrapper(this);
			m_sdk->SetDelegate(m_delegate);
		}
	}
	else
	{
		throw gcnew Exception("./CppProLib.dll");
	}
}

MclAuthWrapper::~MclAuthWrapper()
{

}

void MclAuthWrapper::Login(unsigned int uid, String^ ip, int port)
{
	msclr::interop::marshal_context context;
	const char* cip = context.marshal_as<const char*>(ip);
	m_sdk->Login(uid, cip, port);
}


void MclAuthWrapper::CallOnLoginFinish(int code)
{
	OnLoginFinish(code);
}