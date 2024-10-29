#include "Character.h"
#include "Labyrinth.h"

Character::Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name, Labyrinth* lab)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng), laberynth(lab)
{
}

Character::~Character()
{
}

void Character::frameRendered(const Ogre::FrameEvent& evt)
{
	if (laberynth->checkDirection(direction))
		mNode->translate(Vector3{ 0, 0, 1 }, Ogre::Node::TransformSpace::TS_LOCAL);
}

void Character::setDirection(Vector3 newDir)
{
	if (newDir != rotateDirection) {
		rotateDirection = newDir;
		if (laberynth->checkDirection(rotateDirection))
			rotate();
		//cout << direction << endl;
	}
}

void Character::rotate()
{
	Quaternion q = this->getOrientation().getRotationTo(rotateDirection);
	mNode->rotate(q);
	direction = rotateDirection;
}
