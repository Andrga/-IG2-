#include "OgreHeadIntro.h"

OgreHeadIntro::OgreHeadIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab)
	: Character(initPos, node, sceneMng, "headIntro", lab)
{
	entity = sceneMng->createEntity("ogrehead.mesh");
	mNode->attachObject(entity);
	this->setPosition(initialPosition);
}

OgreHeadIntro::~OgreHeadIntro()
{

}

void OgreHeadIntro::update(float t)
{
}
