#include "HeroIntro.h"

HeroIntro::HeroIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab)
	: Character(initPos, node, sceneMng, "heroIntro", lab)
{
	entity = sceneMng->createEntity("Sinbad.mesh");
	mNode->attachObject(entity);
	this->setPosition(initialPosition);

	dance = getAnim("Dance");
	walk = getAnim("Dance");
	//dance = getAnim("sinbadWalking");

}

HeroIntro::~HeroIntro()
{

}

void HeroIntro::update()
{



}

AnimationState* HeroIntro::getAnim(std::string anim)
{
	return entity->getAnimationState(anim);
}

AnimationState* HeroIntro::addTrack(SceneManager* sMng)
{// Variables
	int movementLength = 50;
	Real duration = 16.0;
	Vector3 keyframePos(0, 0, 0);
	Quaternion keyframeRot;
	//Quaternion keyframeRot(0, 0, 0, 0);
	Real durStep = duration / 4.0;

	// Create the animation and track
	Ogre::Animation* anim = sMng->createAnimation("sinbadWalking", duration);
	anim->setInterpolationMode(Ogre::Animation::IM_SPLINE);
	//anim->setDefaultRotationInterpolationMode();
	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0);
	track->setAssociatedNode(mNode);
	TransformKeyFrame* kf;

	// Keyframe 0 (Init state)
	kf = track->createNodeKeyFrame(durStep * 0);
	keyframeRot = Quaternion(Degree(0), Vector3(0, 1, 0));
	kf->setScale({ 20, 20, 20 });
	kf->setTranslate(keyframePos);

	// Keyframe 1: Go to the right
	kf = track->createNodeKeyFrame(durStep * 1);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	keyframeRot = Quaternion(Degree(90), Vector3(0, 1, 0));
	kf->setScale({ 20, 20, 20 });
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// Keyframe 2: Go to the initial position
	kf = track->createNodeKeyFrame(durStep * 2);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_X * movementLength;
	keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setScale({ 20, 20, 20 });
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// Keyframe 3: Go to the left
	kf = track->createNodeKeyFrame(durStep * 3);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_X * movementLength;
	keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setScale({ 20, 20, 20 });
	kf->setTranslate(keyframePos);

	// Keyframe 4: Go to the right (initital position)
	kf = track->createNodeKeyFrame(durStep * 4);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	keyframeRot = Quaternion(Degree(90), Vector3(0, 1, 0));
	kf->setScale({ 20, 20, 20 });
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	AnimationState* animationState = sMng->createAnimationState("sinbadWalking");
	animationState->setLoop(true);
	animationState->setEnabled(true);

	return animationState;
}