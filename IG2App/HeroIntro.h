#pragma once
#include "Character.h"
#include "OgreAnimation.h"
#include <OgreKeyFrame.h>


class HeroIntro : public Character
{
private:
	AnimationState* dance = nullptr;
	AnimationState* walk = nullptr;
	AnimationState* sword = nullptr;
	AnimationState* movement = nullptr;

	AnimationState* activeAnim = nullptr;

public:

	HeroIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~HeroIntro();

	void update(float t) override;

	void generateTrack(SceneManager* sMng);

	void setAnimState(int id);


};