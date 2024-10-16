#include "Hero.h"
#include "Labyrinth.h"
Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name, Labyrinth* lab)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh), laberynth(lab)
{}

Hero::~Hero()
{

}

void Hero::frameRendered(const Ogre::FrameEvent& evt)
{




	if (laberynth->checkDirection(direction))
		mNode->translate(Vector3{ 0, 0, 1 }, Ogre::Node::TransformSpace::TS_LOCAL);
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

	if (newDir != rotateDirection) {
		rotateDirection = newDir;
		if (laberynth->checkDirection(rotateDirection))
			rotate();
		//cout << direction << endl;
	}

	return false;
}

void Hero::rotate()
{
	Quaternion q = this->getOrientation().getRotationTo(rotateDirection);
	mNode->rotate(q);
	direction = rotateDirection;
}
