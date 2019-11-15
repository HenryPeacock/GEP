#include "Entity.h"
#include "macros.h"

#include <memory>
#include <iostream>
#include <list>

namespace Peacock
{
	class Core
	{
	public:
		shared<Entity> addEntity();
		void run();

		static shared<Core> initialize();

	private:
		std::vector<shared<Entity>> entities;
	};
}