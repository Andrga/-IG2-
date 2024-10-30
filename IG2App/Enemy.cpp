#include "Enemy.h"
#include "Labyrinth.h"

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

Enemy::Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int n, string name, Labyrinth* lab)
	: Character(initPos, node, sceneMng, name, lab)
{

}

void Enemy::frameRendered(const Ogre::FrameEvent& evt)
{
	Character::frameRendered(evt);

	if (laberynth == nullptr)
		return;

	// comprueba la direccion que se acerca mas al jugador y si puede girar lo hace
	Vector3 newDir = laberynth->getDirection(this);
	if (laberynth->checkDirection(this, newDir)) {
		setDirection(newDir);
	}
	// si delante no tiene huecho, gira 180º
	else if (!laberynth->checkDirection(this, direction))
	{
		if (direction == Vector3{ 0,0,1 })
			setDirection(Vector3{ 0,0,-1 });
		else if (direction == Vector3{ 0,0,-1 })
			setDirection(Vector3{ 0,0,1 });
		else if (direction == Vector3{ 1,0,0 })
			setDirection(Vector3{ -1,0,0 });
		else
			setDirection(Vector3{ 1,0,0 });
	}
}
