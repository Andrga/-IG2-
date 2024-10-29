#include "Enemy.h"

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name, Labyrinth* lab)
	: Hero(initPos, node, sceneMng, mesh, name, lab)

{



}

bool Enemy::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	return false;
}
