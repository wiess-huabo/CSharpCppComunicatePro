#pragma once

#include <iostream>
#include <vcclr.h>

//#pragma managed(push, off)
#include "../CppProLib/imclauth.h"
#include "../CppProLib/mclsdkdelegate.h"
//#pragma managed(pop)

using namespace System;

namespace AuthSdkWrapper
{
	class DelegateWrapper;

	public ref class MclAuthWrapper abstract
	{
	public:
		MclAuthWrapper();
		~MclAuthWrapper();

		void Login(unsigned int uid, String^ ip, int port);

	internal:
		void CallOnLoginFinish(int code);

	protected:
		virtual void OnLoginFinish(int code) = 0;

	private:
		AuthSdk::IMclAuth *m_sdk = NULL;
		DelegateWrapper* m_delegate = NULL;
	};

	public class DelegateWrapper : public AuthSdk::MclSdkDelegate
	{
	public:
		DelegateWrapper(MclAuthWrapper^ owner) { m_owner = owner; }

		void OnLoginFinish(int code) override
		{
			m_owner->CallOnLoginFinish(code);
		}

	private:
		gcroot<MclAuthWrapper^> m_owner;
	};
}

