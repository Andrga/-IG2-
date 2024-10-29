#include "MasterEnemy.h"

MasterEnemy::MasterEnemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name, Labyrinth* lab)
	: Enemy(initPos, node, sceneMng, mesh, name, lab)
{
	mMaster = node->createChildSceneNode("master");

	mPenguin = node->createChildSceneNode("body");
	Ogre::Entity* penguin1 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* penguin2 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* penguin3 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* penguin4 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* penguin5 = sceneMng->createEntity("penguin.mesh");





}