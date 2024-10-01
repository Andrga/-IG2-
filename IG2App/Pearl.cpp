#include "Pearl.h"

Pearl::Pearl(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name) :
	IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh)
{

}

Pearl::~Pearl()
{

}
