#include <PeacockEngine/PeacockEngine.h>

#include <iostream>
#include <memory>

class TriangleRenderer : public Component
{
	void onDisplay()
	{
		std::cout << "Triangle Boi" << std::endl;
	}
};

int main()
{
	std::cout<<"Fortnite Bad"<<std::endl<<"Minecraft Good"<<std::endl;
	
	shared<Core> core = Core::initialize();

	shared<Entity> entity = core->addEntity();
	shared<TriangleRenderer> tr = entity->addComponent<TriangleRenderer>();

	core->run();
	
	std::cin.get();
	return 0;
}