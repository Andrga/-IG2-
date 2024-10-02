#include "Hero.h"

Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh)
{}

Hero::~Hero()
{

}
