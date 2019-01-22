#include "nativeapi.h"
#include "mclauth.h"
#include <cstddef>

using namespace AuthSdk;

IMclAuth *m_instance = NULL;

NATIVE_API IMclAuth* GetInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new AuthSdk::MclAuth();
	}

	return m_instance;
}
