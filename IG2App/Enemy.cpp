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
	if (isCenter()) {

		Vector3 newDir = laberynth->getDirection(this);
		if (laberynth->checkDirection(this, newDir)) {
			//cout << "Nueva direccion de enemigo" << newDir << endl;
			rotateDirection = newDir;
			return;
		}

		// si delante no tiene huecho, gira 180º
		else if (!laberynth->checkDirection(this, direction))
		{
			rotateDirection = -direction;
		}
	}
}
