#include "Resource.h"


Peacock::Resource::~Resource() { }

shared<Core> Peacock::Resource::getCore()
{
	return m_core.lock();
}
