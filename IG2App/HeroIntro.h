#pragma once
#include "Character.h"
#include "OgreAnimation.h"
#include <OgreKeyFrame.h>


class HeroIntro : public Character
{
private:
	AnimationState* dance = nullptr;
	AnimationState* walk = nullptr;
	//AnimationState* dance = nullptr;


public:

	HeroIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~HeroIntro();

	void update() override;

	AnimationState* getAnim(std::string anim);

	AnimationState* addTrack(SceneManager* sMng);


};