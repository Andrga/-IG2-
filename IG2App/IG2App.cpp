#include "IG2App.h"

using namespace Ogre;
using namespace std;

#include "Wall.h"
#include "MasterEnemy.h"

void IG2App::nextLaberynth()
{
	delete laberinto;
	laberinto = new Labyrinth(LABERINTO2, mSM->getRootSceneNode(), mSM);
}



bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt) {

	// ESC key finished the rendering...
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
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

void IG2App::setupScene(void) {

	//------------------------------------------------------------------------
	// Creating the camera

	Camera* cam = mSM->createCamera("Cam");
	cam->setNearClipDistance(1);
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);

	mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
	mCamNode->attachObject(cam);

	mCamNode->lookAt(Ogre::Vector3(0, 1, 0), Ogre::Node::TS_WORLD);

	// and tell it to render into the main window
	Viewport* vp = getRenderWindow()->addViewport(cam);

	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0, 1));

	mCamMgr = new OgreBites::CameraMan(mCamNode);
	addInputListener(mCamMgr);
	mCamMgr->setStyle(OgreBites::CS_ORBIT);

	mCamNode->setPosition(900, 2600, 1000); // PAIGRO AQUI: deberia cambiar dependiendo del mapa.


	/*//------------------------------------------------------------------------
	// Creating the light

	//mSM->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
	Light* luz = mSM->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);

	mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
	//mLightNode = mCamNode->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0.5, -1.0, 0.5));



	//------------------------------------------------------------------------//*/

	laberinto = new Labyrinth(LABERINTO2, mSM->getRootSceneNode(), mSM);

	hero = laberinto->getHero();
	std::vector<Enemy*> enemies = laberinto->getEnemies();

	for (auto e : enemies)
	{
		addInputListener(e);
	}
	addInputListener(hero);

	//-------------CREACION DE LA UI------------//
	label = mTrayMgr->createLabel(OgreBites::TL_BOTTOMRIGHT, "StageInfo", "Stage 1", 250);
	textBox = mTrayMgr->createTextBox(OgreBites::TL_BOTTOMRIGHT, "GameInfo:", "GameInfo:", 250, 100);


	createLight();
}

bool IG2App::frameEnded(const Ogre::FrameEvent& evt)
{
	// Actualizamos la ui
	textBox->clearText();
	textBox->appendText(" Lives: " + to_string(lives) + "\nPoints: " + to_string(laberinto->getPoints()));

	if (laberinto->getPoints() >= laberinto->getMaxPoints())
		nextLaberynth();

	if (laberinto->checkCollision())
	{
		lives--;
		laberinto->setInvulnerable();
	}

	if (lives <= 0)
	{
		getRoot()->queueEndRendering();
	}

	if (lightMoves && hero != nullptr && mLightNode != nullptr)
		mLightNode->setPosition(hero->getPosition().x - 300, 500, hero->getPosition().z - 300); // Por alguna razon tiene ese offset...

	return IG2ApplicationContext::frameEnded(evt);
}

void IG2App::createLight()
{
	Light* luz = mSM->createLight("Luz");

	switch (toupper(laberinto->getLightType()))
	{
	case 'D': // Luz direccional
		std::cout << "Luz direccional." << std::endl;
		luz->setType(Ogre::Light::LT_DIRECTIONAL);
		break;

	case 'S': // Luz spot.
		std::cout << "Luz spot." << std::endl;
		luz->setType(Ogre::Light::LT_SPOTLIGHT);
		lightMoves = true;
		break;

	case 'P': // Luz point.
		std::cout << "Luz point." << std::endl;
		luz->setType(Ogre::Light::LT_POINT);
		break;

	default: // Default por si acaso.
		std::cout << "Luz default: direccional." << std::endl;
		luz->setType(Ogre::Light::LT_DIRECTIONAL);
		break;
	}

	//mSM->setAmbientLight(ColourValue(0.5, 0.5, 0.5));


	luz->setDiffuseColour(0.75, 0.75, 0.75);

	mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0.5, -1.0, 0.5));
	mLightNode->setPosition(laberinto->getCenter().x, laberinto->getCenter().y + 1000, laberinto->getCenter().z);
}