#pragma once

#include "Enemy.h"

//class Labyrinth;

class MasterEnemy : public Enemy
{
private:

	Ogre::SceneNode* mMaster = nullptr;
	Ogre::SceneNode* mBDer = nullptr;
	Ogre::SceneNode* mBody = nullptr;
	Ogre::SceneNode* mBIzq = nullptr;


public:

	MasterEnemy();
	MasterEnemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name = "enemy", Labyrinth* lab = nullptr);

};