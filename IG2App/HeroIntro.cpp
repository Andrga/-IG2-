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

void HeroIntro::generateTrack(SceneManager* sMng)
{
	// Variables
	int movementLength = 50;
	Real duration = 16.0;
	Vector3 keyframePos(0, 10, 0);
	Vector3 keyframeScale(10, 10, 10);
	Quaternion keyframeRot(0, 0, 0, 0);
	Real durStep = duration / 4.0;

	// Create the animation and track
	Ogre::Animation* anim = sMng->createAnimation("sinbadWalking", duration);
	anim->setInterpolationMode(Ogre::Animation::IM_LINEAR);
	//anim->setDefaultRotationInterpolationMode();
	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0);
	track->setAssociatedNode(mNode);
	TransformKeyFrame* kf;

	// Keyframe 0 (Init state)
	kf = track->createNodeKeyFrame(0);
	keyframeRot = Quaternion(Degree(0), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// TURN KEYFRAME
	kf = track->createNodeKeyFrame(0.5);
	keyframeRot = Quaternion(Degree(90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// Keyframe 1: Go to the right
	kf = track->createNodeKeyFrame(4);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	keyframeRot = Quaternion(Degree(90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// TURN KEYFRAME
	kf = track->createNodeKeyFrame(4.25);
	keyframeRot = Quaternion(Degree(90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// TURN KEYFRAME
	kf = track->createNodeKeyFrame(4.75);
	keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// Keyframe 2: Go to the initial position
	kf = track->createNodeKeyFrame(8);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_X * movementLength;
	//keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);


	// Keyframe 3: Go to the left
	kf = track->createNodeKeyFrame(12);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_X * movementLength;
	//keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setRotation(keyframeRot);
	kf->setScale(keyframeScale);
	kf->setTranslate(keyframePos);

	// TURN KEYFRAME
	kf = track->createNodeKeyFrame(12.25);
	//keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// TURN KEYFRAME
	kf = track->createNodeKeyFrame(12.75);
	keyframeRot = Quaternion(Degree(90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// Keyframe 4: Go to the right (initital position)
	kf = track->createNodeKeyFrame(15.5);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	keyframeRot = Quaternion(Degree(-90), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	// TURN KEYFRAME
	kf = track->createNodeKeyFrame(16);
	keyframeRot = Quaternion(Degree(0), Vector3(0, 1, 0));
	kf->setScale(keyframeScale);
	kf->setRotation(keyframeRot);
	kf->setTranslate(keyframePos);

	movement = sMng->createAnimationState("sinbadWalking");
	

}

void HeroIntro::setAnimState(int id)
{
	switch (id)
	{
	case 1:
		dance->setLoop(true);
		dance->setEnabled(true);
		break;
	case 2:
		movement->setLoop(true);
		movement->setEnabled(true);
		break;
	case 3:
		movement->setLoop(true);
		movement->setEnabled(true);
	default:
		break;
	}
}
