#pragma once

#include "Character.h"



class Enemy : public Character
{
public:

	Enemy();
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name = "enemy", Labyrinth* lab = nullptr);

};