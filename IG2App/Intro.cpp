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
	Light* luz = sMang->createLight("LuzIntro");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);
	mLightNode = sMang->getRootSceneNode()->createChildSceneNode("nLuzIntro");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0.0, -1.0, 0.0)); // Apunta hacia abajo.

	hero = new HeroIntro({ 0, 0, 0 }, introNode, sMang);

	hero->setScale({ 20, 20, 20 });

	head = new OgreHeadIntro();

	animationStateDance = hero->setAnim("Dance");
	animationStateDance->setLoop(true);
	animationStateDance->setEnabled(true);
}


void Intro::setVisible(bool vis)
{
	introNode->setVisible(vis);
}

void Intro::update(const Ogre::FrameEvent& evt)
{
	if (animationStateDance != nullptr)
	{
		animationStateDance->addTime(evt.timeSinceLastFrame);
	}



}

void Intro::trackMovimiento()
{
	// Variables
	int movementLength = 50;
	Real duration = 16.0;
	Vector3 keyframePos(0, 0, 0);
	Real durStep = duration / 4.0;

	// Create the animation and track
	Ogre::Animation* animation = sMang->createAnimation("sinbadWalking", duration);
	animation->setInterpolationMode(Ogre::Animation::IM_SPLINE);
	Ogre::NodeAnimationTrack* track = animation->createNodeTrack(0);
	track->setAssociatedNode(hero);
	TransformKeyFrame* kf;
}
