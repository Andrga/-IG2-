#pragma once

#include "Enemy.h"
#include "OgreTimer.h"

class MasterEnemy : public Enemy
{
private:

	Ogre::SceneNode* mBody = nullptr; // Nodo que contiene los 3 pinguinos del cuerpo y el sombrero razor.
	Ogre::SceneNode* mBDer = nullptr; // Nodo que contiene el pinguino del brazo derecho.
	Ogre::SceneNode* mBIzq = nullptr; // Nodo que contiene el pinguino del brazo derecho.
	Ogre::SceneNode* mFDer = nullptr; // Nodo que contiene los pescados del brazo derecho.
	Ogre::SceneNode* mFIzq = nullptr; // Nodo que contiene los pescados del brazo izquierdo.

	Ogre::Timer* timer;
	float timeToMove = 3;
public:
	
	//------Constructoras y destructoras:

	// Cosntructora de MasterEnemy base.
	MasterEnemy();
	// Constructora de MasterEnemy con posicion, nodo, sceneManager, nombre y referencia al laberinto.
	MasterEnemy(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name = "enemy", Labyrinth* lab = nullptr);

	//------Metodos heredados:

	// Sobre carga del frameRenderer que hace de Update.
	void frameRendered(const Ogre::FrameEvent& evt) override;
};