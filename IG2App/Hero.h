#pragma once

#include "Character.h"

class Labyrinth;


class Hero : public Character
{

public:

	Hero() : Character() {}
	Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~Hero();
	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
};