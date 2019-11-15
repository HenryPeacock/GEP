#ifndef PEACOCKENGINE_COMPONENT_H
#define PEACOCKENGINE_COMPONENT_H

#include <memory>
#include <iostream>

namespace Peacock
{
	class Component
	{
	public:
		virtual void onInitialize();
		virtual void onTick();
		virtual void onDisplay();

	};
}
#endif
