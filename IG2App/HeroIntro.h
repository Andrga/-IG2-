#pragma once
#include "Character.h"

class HeroIntro : public Character
{
private:



public:

	HeroIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~HeroIntro();

	void update() override;

	AnimationState* setAnim(std::string anim);
};