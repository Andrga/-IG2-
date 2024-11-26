#pragma once

#include "Character.h"



class Enemy : public Character
{


public:

	Enemy();
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name = "enemy", Labyrinth* lab = nullptr);
	Enemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int n, string name = "enemy", Labyrinth* lab = nullptr);

	//void frameRendered(const Ogre::FrameEvent& evt) override;
	void update(float t) override;
};