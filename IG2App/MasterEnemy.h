#pragma once

#include "Enemy.h"

class Labyrinth;

class MasterEnemy : public Enemy
{
private:

	Ogre::SceneNode* mMaster = nullptr;
	Ogre::SceneNode* mFish = nullptr;
	Ogre::SceneNode* mPenguin = nullptr;
	Ogre::SceneNode* mNinja = nullptr;

public:

	MasterEnemy();
	MasterEnemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "ogrehead.mesh", string name = "enemy", Labyrinth* lab = nullptr);

};