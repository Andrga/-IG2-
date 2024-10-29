#include "MasterEnemy.h"

MasterEnemy::MasterEnemy()
{
}

MasterEnemy::MasterEnemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name, Labyrinth* lab)
	: Enemy(initPos, node, sceneMng, mesh, name, lab)
{
	
	mMaster = node->createChildSceneNode("master");

	// Cuerpo
	mBody = mMaster->createChildSceneNode("body");
	// Creamos entidades
	Ogre::Entity* penguin1 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* penguin2 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* penguin3 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* razor = sceneMng->createEntity("razor.mesh");
	// Aniadimos entidades al nodo
	mBody->attachObject(penguin1);
	mBody->attachObject(penguin2);
	mBody->attachObject(penguin3);
	mBody->attachObject(razor);

	// Brazo izq
	mBDer = mMaster->createChildSceneNode("BrazoDer");
	Ogre::Entity* penguin4 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* fish1 = sceneMng->createEntity("fish.mesh");
	Ogre::Entity* fish2 = sceneMng->createEntity("fish.mesh");
	mBDer->attachObject(penguin4);
	mBDer->attachObject(fish1);
	mBDer->attachObject(fish2);


	// Brazo der
	mBIzq = mMaster->createChildSceneNode("BrazoIzq");
	Ogre::Entity* penguin5 = sceneMng->createEntity("penguin.mesh");
	Ogre::Entity* fish3 = sceneMng->createEntity("fish.mesh");
	Ogre::Entity* fish4 = sceneMng->createEntity("fish.mesh");
	mBDer->attachObject(penguin5);
	mBDer->attachObject(fish3);
	mBDer->attachObject(fish4);




	
}