#pragma once
namespace AuthSdk
{
	class MclSdkDelegate
	{
	public:
		virtual void OnLoginFinish(int code) = 0;
		
	};
}