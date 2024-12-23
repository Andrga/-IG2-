#include "Hero.h"
#include "Labyrinth.h"
Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab)
	:Character(initPos, node, sceneMng, "hero", lab)
{
	entity = sceneMng->createEntity("Sinbad.mesh");
	mNode->attachObject(entity);
	this->setPosition(initialPosition);
	timer = new Timer();
}

Hero::~Hero()
{
	cout << "---Sinbad Eliminado---" << endl;
}

bool Hero::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	Vector3 newDir;
	switch (evt.keysym.sym)
	{
	case SDLK_UP:
		rotateDirection = { 0, 0, 1 };
		//cout << "UP" << endl;
		break;
	case SDLK_DOWN:
		rotateDirection = { 0, 0, -1 };
		//cout << "DOWN" << endl;
		break;
	case SDLK_LEFT:
		rotateDirection = { 1, 0, 0 };
		//cout << "LEFT" << endl;
		break;
	case SDLK_RIGHT:
		rotateDirection = { -1, 0, 0 };
		//cout << "RIGHT" << endl;
		break;
	default:
		break;
	}

	return false;
}

void Hero::frameRendered(const Ogre::FrameEvent& evt)
{
	Character::frameRendered(evt);

	if (timer->getMilliseconds() / 1000 >= timeinvincible)
	{
		invincible = false;
		timer->reset();
	}
}
