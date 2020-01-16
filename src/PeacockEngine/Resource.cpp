#include "Resource.h"


Resource::~Resource() { }

shared<Core> Resource::GetCore()
{
	return m_core.lock();
}
