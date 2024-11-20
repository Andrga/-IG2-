#pragma once
#include "Character.h"

class OgreHeadIntro: public Character
{
public:
	OgreHeadIntro(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~OgreHeadIntro();

	void update() override;
};