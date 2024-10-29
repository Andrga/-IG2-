#pragma once

#include "IG2Object.h"
#include "Hero.h"

//class Labyrinth;

class Enemy : public Hero
{
private:



public:

	Enemy();
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "ogrehead.mesh", string name = "enemy", Labyrinth* lab = nullptr);

	void init() override {}

	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
};