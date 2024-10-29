#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name, Labyrinth* lab)
	: Character(initPos, node, sceneMng, name, lab)
{
	entity = sceneMng->createEntity("ogrehead.mesh");
	mNode->attachObject(entity);
	this->setPosition(initialPosition);
}