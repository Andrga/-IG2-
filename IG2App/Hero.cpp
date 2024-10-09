#include "Hero.h"

Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name, Labyrinth* lab)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh), laberynth(lab)
{}

Hero::~Hero()
{

}

void Hero::frameRendered(const Ogre::FrameEvent& evt)
{
	
	mNode->translate(Vector3{ 0, 0, 1 }, Ogre::Node::TransformSpace::TS_LOCAL);
}

bool Hero::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	switch (evt.keysym.sym)
	{
	case SDLK_UP:
		direction = { 0, 0, 1 };

		break;
	case SDLK_DOWN:
		direction = { 0, 0, -1 };

		break;
	case SDLK_LEFT:

		direction = { 1, 0, 0 };

		break;
	case SDLK_RIGHT:

		direction = { -1, 0, 0 };
		break;
	default:
		break;
	}
	rotate();
	return false;
}

void Hero::rotate()
{
	Quaternion q = this->getOrientation().getRotationTo(direction);
	mNode->rotate(q);
}
