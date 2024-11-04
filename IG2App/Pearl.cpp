#include "Pearl.h"

Pearl::Pearl(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string matName, String mesh, string name)
	: Block(initPos, node->createChildSceneNode(name), sceneMng, mesh)
{
	blockType = BLOCK_TYPE::PEARL;
	entity->setMaterialName(matName); //Asignamos el material
}

Pearl::~Pearl()
{

}
