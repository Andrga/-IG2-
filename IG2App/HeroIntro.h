#pragma once
#include "Character.h"
#include "OgreAnimation.h"
#include <OgreKeyFrame.h>


class HeroIntro : public Character
{
private:



public:

	HeroIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~HeroIntro();

	void update() override;

	AnimationState* getAnim(std::string anim);

	AnimationState* addTrack(SceneManager* sMng);


};