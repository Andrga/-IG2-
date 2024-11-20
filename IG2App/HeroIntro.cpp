#include "HeroIntro.h"

HeroIntro::HeroIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab)
	: Character(initPos, node, sceneMng, "heroIntro", lab)
{
	entity = sceneMng->createEntity("Sinbad.mesh");
	mNode->attachObject(entity);
	this->setPosition(initialPosition);
}

HeroIntro::~HeroIntro()
{

}

void HeroIntro::update()
{



}

AnimationState* HeroIntro::setAnim(std::string anim)
{
	return entity->getAnimationState(anim);
}