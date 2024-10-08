#include "Hero.h"

Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh)
{}

Hero::~Hero()
{

}

void Hero::frameRendered(const Ogre::FrameEvent& evt)
{
	mNode->translate(direction);
}

bool Hero::keyPressed(const OgreBites::KeyboardEvent& evt)
{

	switch (evt.keysym.sym)
	{
	case SDLK_UP:
		direction = { 0, 0,1 };

		break;
	case SDLK_DOWN:
		direction = { 0, 0, -1};

		break;
	case SDLK_LEFT:

		direction = { 1, 0,0 };

		break;
	case SDLK_RIGHT:
		
		direction = { -1, 0,0 };
		break;
	default:
		break;
	}

	return false;
}

void Hero::rotate()
{
	if (direction != Vector3{0, 0, 0})
	{

	}
}
