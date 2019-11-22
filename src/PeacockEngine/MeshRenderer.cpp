#include "MeshRenderer.h"
#include "Entity.h"

namespace Peacock
{
	void MeshRenderer::onDisplay()
	{
		std::cout << "Renderer::onDisplay" << std::endl;
		getEntity();//->getCore()->addEntity();
	}
}
