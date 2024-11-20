#include "Intro.h"

Intro::Intro(SceneManager* SM, SceneNode* sNode)
	: sMang(SM), introNode(sNode)
{

	setUpScene();

}

Intro::~Intro()
{



}

void Intro::setUpScene()
{
	hero = new HeroIntro({ 0, 0, 0 }, introNode, sMang);
	head = new OgreHeadIntro();

	AnimationState* animationState = hero->setAnim("Dance");
}


void Intro::setVisible(bool vis)
{
	introNode->setVisible(vis);
}

void Intro::update()
{



}