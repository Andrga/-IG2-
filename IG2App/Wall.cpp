#include "Wall.h"

Wall::Wall(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name) 
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh) {
	cout << name << endl;
}

