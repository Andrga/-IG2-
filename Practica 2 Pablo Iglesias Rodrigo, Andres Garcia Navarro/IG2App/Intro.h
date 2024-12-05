#pragma once

#include "fstream"

#include "IG2Object.h"
#include "string"
#include "HeroIntro.h"
#include "OgreHeadIntro.h"

#include "OgreAnimationTrack.h"
#include <OgreTrays.h>
#include <OgreParticleSystem.h>
#include <OgreTimer.h>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

class Intro
{
private:

	std::vector<Character*> actors; // Vector de los elementos de la intro.

	SceneNode* introNode = nullptr; // Referencia al SceneNode que tiene a Intro.
	SceneManager* sMang = nullptr; // Referencia al SceneManager.

	Camera* introCamera = nullptr; // Referencia a la camara de la intro.

	HeroIntro* hero = nullptr; // Referencia al hero.
	OgreHeadIntro* head = nullptr; // Referencia a la cabeza gigante.

	Ogre::Timer timerHero; // Timer cambio de animacion

	// Nodos:
	Ogre::SceneNode* mLightNode = nullptr; // Referencia al nodo de la luz.
	SceneNode* nGround = nullptr; // Referencia al nodo del suelo.

	AnimationState* animationStateDance = nullptr; // Animacion de Sinbad.

	std::vector<ParticleSystem*> vParSys; // Vector de los sistemas de particulas.

	// UI
	OgreBites::Label* label;
	OgreBites::TextBox* textBox;
public:

	//------Constructuras y destructoras:

	// Constructora base de Intro.
	Intro(SceneManager* SM, SceneNode* sNode, SceneNode* cNode, OgreBites::Label* lbl, OgreBites::TextBox* txtB );
	// Destructora de Intro.
	~Intro();


	//------Metodos de la escena:

	// Crea la escena.
	void setUpScene(SceneNode* cNode);
	// Hace el nivel visible o invisible.
	void setVisible(bool vis);
	// Update de la intro.
	void update(const Ogre::FrameEvent& evt);


	//------Creacion de la escena:
	
	// Crea el plano del suelo.
	void createGround();
	// Crea los fuegos de detras del Hero.
	void createFireParticlesSystems();
	//// Crea la trail que le sale al OgreHead.		PAIGRO AQUI (soy andres te lo he cambiado al ogre head para que sea hijo de su nodo y siga al nodo de la cabeza)
	//void createTrailParticleSystem();
};