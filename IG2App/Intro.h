#pragma once

#include "fstream"

#include "IG2Object.h"
#include "string"
#include "HeroIntro.h"
#include "OgreHeadIntro.h"
#include "OgreAnimationTrack.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <OgreParticleSystem.h>


class Intro
{
private:

	std::vector<Character*> actors; // Vector de los elementos de la intro.

	SceneNode* introNode = nullptr; // Referencia al SceneNode que tiene a Intro.
	SceneManager* sMang = nullptr; // Referencia al SceneManager.

	Camera* introCamera = nullptr; // Referencia a la camara de la intro.

	HeroIntro* hero = nullptr; // Referencia al hero.
	OgreHeadIntro* head = nullptr; // Referencia a la cabeza gigante.

	// Nodos:
	Ogre::SceneNode* mLightNode = nullptr; // Nodo de la luz.
	SceneNode* nGround = nullptr; // Nodo del suelo.

	AnimationState* animationStateDance = nullptr; // Animacion de Sinbad.

	std::vector<ParticleSystem*> vParSys;


public:

	Intro(SceneManager* SM, SceneNode* sNode);
	~Intro();

	void setUpScene();
	void setVisible(bool vis);

	void update(const Ogre::FrameEvent& evt);

	// Crea el plano del suelo.
	void createGround();
	// Crea los fuegos de detras del Hero.
	void createFireParticlesSystems();

private:
	void trackMovimiento();
};