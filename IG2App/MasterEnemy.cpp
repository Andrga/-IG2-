#include "MasterEnemy.h"

MasterEnemy::MasterEnemy()
{

}

MasterEnemy::MasterEnemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name, Labyrinth* lab)
	: Enemy(initPos, node, sceneMng, 1, name, lab)
{
	Vector3 auxPos = initPos; // Vector auxiliar porque si.


	//----Cuerpo:
	mBody = mNode->createChildSceneNode("body");
	mBody->setPosition(auxPos);
	// Primer pinguino que es el cuerpo como tal.
	Ogre::SceneNode* nPenguin1 = mBody->createChildSceneNode("penguin1");
	Ogre::Entity* ePenguin1 = sceneMng->createEntity("penguin.mesh");
	nPenguin1->attachObject(ePenguin1);
	nPenguin1->setPosition(auxPos);
	// Segundo pinguino que es como la pata derecha
	Ogre::SceneNode* nPenguin2 = mBody->createChildSceneNode("penguin2");
	Ogre::Entity* ePenguin2 = sceneMng->createEntity("penguin.mesh");
	nPenguin2->attachObject(ePenguin2);
	nPenguin2->setPosition(auxPos + Vector3(15, -45, 0)); // PAIGRO AQUI: no numero magicos hacerlos en constexpr llamados offsert.
	// Tercer pinguino que es como la pata izquierda.
	Ogre::SceneNode* nPenguin3 = mBody->createChildSceneNode("penguin3");
	Ogre::Entity* ePenguin3 = sceneMng->createEntity("penguin.mesh");
	nPenguin3->attachObject(ePenguin3);
	nPenguin3->setPosition(auxPos + Vector3(-15, -45, 0));
	// Razor que es como el sombrero.
	Ogre::SceneNode* nRazor = mBody->createChildSceneNode("razor");
	Ogre::Entity* eRazor = sceneMng->createEntity("razor.mesh");
	nRazor->attachObject(eRazor);
	nRazor->setScale(0.4, 0.4, 0.4);
	nRazor->setPosition(nPenguin1->getPosition() + Vector3(0, 25, 10));


	//----Brazo derecho:
	mBDer = mBody->createChildSceneNode("brazoDer");
	mBDer->setPosition(auxPos + Vector3(60, -10, 0));
	// Pinguino que es como el brazo derecho.
	Ogre::SceneNode* nPenguinDer = mBDer->createChildSceneNode("penguinDer");
	Ogre::Entity* ePenguinDer = sceneMng->createEntity("penguin.mesh");
	nPenguinDer->attachObject(ePenguinDer);
	nPenguinDer->setScale(0.7, 1.5, 0.7);
	nPenguinDer->roll(Ogre::Degree(90));

	//--Pescados brazo derecho:
	mFDer = mBDer->createChildSceneNode("pescadosDer");
	mFDer->setPosition(Vector3(40, 0, 0));
	// Pescado 1 del brazo derecho.
	Ogre::SceneNode* nFishDer1 = mFDer->createChildSceneNode("fishDer1");
	Ogre::Entity* eFishDer1 = sceneMng->createEntity("fish.mesh");
	nFishDer1->attachObject(eFishDer1);
	nFishDer1->setScale(7, 7, 7);
	nFishDer1->setPosition(Vector3(0, 0, 30));
	nFishDer1->yaw(Ogre::Degree(-90));
	// Pescado 2 del brazo derecho.
	Ogre::SceneNode* nFishDer2 = mFDer->createChildSceneNode("fishDer2");
	Ogre::Entity* eFishDer2 = sceneMng->createEntity("fish.mesh");
	nFishDer2->attachObject(eFishDer2);
	nFishDer2->setScale(7, 7, 7);
	nFishDer2->setPosition(Vector3(0, 0, -30));
	nFishDer2->yaw(Ogre::Degree(90));


	//----Brazo izquierdo:
	mBIzq = mBody->createChildSceneNode("brazoIzq");
	mBIzq->setPosition(auxPos + Vector3(-60, -10, 0));
	// Pinguino que es como el brazo izquierdo.
	Ogre::SceneNode* nPenguinIzq = mBIzq->createChildSceneNode("penguinIzq");
	Ogre::Entity* ePenguinIzq = sceneMng->createEntity("penguin.mesh");
	nPenguinIzq->attachObject(ePenguinIzq);
	nPenguinIzq->setScale(0.7, 1.5, 0.7);
	nPenguinIzq->roll(Ogre::Degree(-90));

	//--Pescados brazo izquierdo:
	mFIzq = mBIzq->createChildSceneNode("pescadosIzq");
	mFIzq->setPosition(Vector3(-40, 0, 0));
	// Pescado 1 del brazo izquierdo.
	Ogre::SceneNode* nFishIzq1 = mFIzq->createChildSceneNode("fishIzq1");
	Ogre::Entity* eFishIzq1 = sceneMng->createEntity("fish.mesh");
	nFishIzq1->attachObject(eFishIzq1);
	nFishIzq1->setScale(7, 7, 7);
	nFishIzq1->setPosition(Vector3(0, 0, 30));
	nFishIzq1->yaw(Ogre::Degree(-90));
	// Pescado 1 del brazo izquierdo.
	Ogre::SceneNode* nFishIzq2 = mFIzq->createChildSceneNode("fishIzq2");
	Ogre::Entity* eFishIzq2 = sceneMng->createEntity("fish.mesh");
	nFishIzq2->attachObject(eFishIzq2);
	nFishIzq2->setScale(7, 7, 7);
	nFishIzq2->setPosition(Vector3(0, 0, -30));
	nFishIzq2->yaw(Ogre::Degree(90));
}

void MasterEnemy::frameRendered(const Ogre::FrameEvent& evt)
{
	Enemy::frameRendered(evt);
	if (timer->getMilliseconds()*100 <= timeToMove)
	{
		mBIzq->pitch(Ogre::Degree(-2), Ogre::Node::TS_LOCAL);
		mFIzq->pitch(Ogre::Degree(4), Ogre::Node::TS_LOCAL);
		mBDer->pitch(Ogre::Degree(-2), Ogre::Node::TS_LOCAL);
		mFDer->pitch(Ogre::Degree(4), Ogre::Node::TS_LOCAL);
	}
	else
	{
		timer->reset();
	}
}