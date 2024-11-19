#include "IG2App.h"

using namespace Ogre;
using namespace std;

#include "Wall.h"
#include "MasterEnemy.h"

void IG2App::nextLaberynth()
{
	delete laberinto;
	laberinto = new Labyrinth(LABERINTO2, mSM->getRootSceneNode(), mSM, mCamNode);
}



bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt) {

	// ESC key finished the rendering...
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}
	if (evt.keysym.sym == SDLK_s) {
		if (intro == nullptr || laberinto == nullptr) return false;
		intro->setVisible(false);
		laberinto->setVisible(true);
	}

	//cout << "Orientacion: " << mCamMgr->getCamera()->getOrientation() << endl;
	//cout << "Posicion: " << mCamMgr->getCamera()->getPosition() << endl;

	if (hero == nullptr)
		return false;

	hero->keyPressed(evt);
	return true;
}

void IG2App::shutdown() {

	mShaderGenerator->removeSceneManager(mSM);
	mSM->removeRenderQueueListener(mOverlaySystem);

	mRoot->destroySceneManager(mSM);

	delete mTrayMgr;  mTrayMgr = nullptr;
	delete mCamMgr; mCamMgr = nullptr;

	// do not forget to call the base 
	IG2ApplicationContext::shutdown();
}

void IG2App::setup(void) {

	// do not forget to call the base first
	IG2ApplicationContext::setup();

	// Create the scene manager
	mSM = mRoot->createSceneManager();

	// Register our scene with the RTSS
	mShaderGenerator->addSceneManager(mSM);

	mSM->addRenderQueueListener(mOverlaySystem);
	mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);
	mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	addInputListener(mTrayMgr);

	// Adds the listener for this object
	addInputListener(this);
	setupScene();
}

void IG2App::setupScene(void) 
{
	mSM->setShadowTechnique(ShadowTechnique::SHADOWTYPE_STENCIL_ADDITIVE); // Creo que he puesto sombras.

	//------------------------------------------------------------------------
	// Creating the camera

	Camera* cam = mSM->createCamera("Cam");
	cam->setNearClipDistance(1);
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);

	mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
	mCamNode->attachObject(cam);

	mCamNode->lookAt(Ogre::Vector3(0, 1, 0), Ogre::Node::TS_WORLD); // Mira hacia abajo.

	// and tell it to render into the main window
	Viewport* vp = getRenderWindow()->addViewport(cam);

	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0, 1)); // Fondo de la escena negro.

	mCamMgr = new OgreBites::CameraMan(mCamNode);
	addInputListener(mCamMgr);
	mCamMgr->setStyle(OgreBites::CS_ORBIT);

	nIntro = mSM->getRootSceneNode()->createChildSceneNode();
	nGame = mSM->getRootSceneNode()->createChildSceneNode();
	// ----------CREACION DEL JUEGO----------//
	laberinto = new Labyrinth(LABERINTO1,nGame, mSM, mCamNode);

	hero = laberinto->getHero();
	std::vector<Enemy*> enemies = laberinto->getEnemies();

	// ----------ANIADE ENEMIGOS COMO INPUT LISTENERS----------//
	for (auto e : enemies)
	{
		addInputListener(e);
	}
	addInputListener(hero);

	laberinto->setVisible(false);
	
	//--------------CREACION DE LA INTRO-------------//
	intro = new Intro(mSM, nIntro);
	
	
	//-------------CREACION DE LA UI------------//
	label = mTrayMgr->createLabel(OgreBites::TL_BOTTOMRIGHT, "StageInfo", "Stage 1", 250);
	textBox = mTrayMgr->createTextBox(OgreBites::TL_BOTTOMRIGHT, "GameInfo:", "GameInfo:", 250, 100);
}

bool IG2App::frameEnded(const Ogre::FrameEvent& evt)
{
	// Actualizamos la ui
	textBox->clearText();
	textBox->appendText(" Lives: " + to_string(lives) + "\nPoints: " + to_string(laberinto->getPoints()));

	laberinto->update();

	if (laberinto->getPoints() >= laberinto->getMaxPoints())
		nextLaberynth();

	if (laberinto->checkEnemyCollision())
	{
		lives--;
		laberinto->setInvulnerable();
	}

	if (lives <= 0)
	{
		getRoot()->queueEndRendering();
	}

	laberinto->updateLight(); // Actualizamos la camara.

	return IG2ApplicationContext::frameEnded(evt);
}