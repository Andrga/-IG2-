#include "Hero.h"
#include "Labyrinth.h"
Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab)
	:Character(initPos, node, sceneMng, "hero", lab)
{
	entity = sceneMng->createEntity("Sinbad.mesh");
	mNode->attachObject(entity);
	this->setPosition(initialPosition);
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
		newDir = { 0, 0, 1 };

		break;
	case SDLK_DOWN:
		newDir = { 0, 0, -1 };

		break;
	case SDLK_LEFT:

		newDir = { 1, 0, 0 };

		break;
	case SDLK_RIGHT:

		newDir = { -1, 0, 0 };
		break;
	default:
		break;
	}

	setDirection(newDir);

	return false;
}