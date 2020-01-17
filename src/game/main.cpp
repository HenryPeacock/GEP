#include <PeacockEngine/PeacockEngine.h>
#include <iostream>
#include <memory>




int main()
{
	shared<Core> core = core->Initialize();

	shared<SoundSource> testSound = core->GetResources()->Load<SoundSource>("../resources/sounds/Sound.ogg");

	shared<Entity> entity = core->AddEntity();
	shared<MeshRenderer> meshRenderer = entity->AddComponent<MeshRenderer>("../resources/shaders/shader.shader");

	shared<PMesh> mesh = core->GetResources()->Load<PMesh>("../resources/model/balloon");
	meshRenderer->SetMesh(mesh);

	shared<Material> material = core->GetResources()->Load<Material>("../resources/model/balloon_red_diffuse.png");
	meshRenderer->SetMaterial(material);

	
	core->Run();

	return 0;
}