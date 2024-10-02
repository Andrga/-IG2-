#include "IG2App.h"

using namespace Ogre;
using namespace std;

#include "Wall.h"

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt) {

	// ESC key finished the rendering...
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}

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

	mCamNode->setPosition(0, 0, 1000);
	mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	// and tell it to render into the main window
	Viewport* vp = getRenderWindow()->addViewport(cam);

	vp->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));

	mCamMgr = new OgreBites::CameraMan(mCamNode);
	addInputListener(mCamMgr);
	mCamMgr->setStyle(OgreBites::CS_ORBIT);


	//------------------------------------------------------------------------
	// Creating the light

	//mSM->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
	Light* luz = mSM->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);

	mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
	//mLightNode = mCamNode->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0.5, -1.0, 0.5));



	////------------------------------------------------------------------------
	//// Creating Sinbad

	//Ogre::Entity* ent1 = mSM->createEntity("Sinbad.mesh");
	//mSinbad = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
	//mSinbad->attachObject(ent1);

	//// Show bounding box
	//mSinbad->showBoundingBox(true);

	//// Set position of Sword
	//mSinbad->setPosition(0, 100, 0);

	//// Set scale of Sword
	//mSinbad->setScale(20, 20, 20);

	////mFacialNode->yaw(Ogre::Degree(-45));
	////mFacialNode->setVisible(false);    
	//
	////------------------------------------------------------------------------
	//// Creating lowBath

	//Ogre::Entity* ent2 = mSM->createEntity("RomanBathLower.mesh");
	//mRBLower = mSM->getRootSceneNode()->createChildSceneNode("nRBLower");
	//mRBLower->attachObject(ent2);

	//// Show bounding box
	//mRBLower->showBoundingBox(true);

	//// Set scale of Sword
	//mRBLower->setScale(1, 1, 1);
	//
	////------------------------------------------------------------------------
	//// Creating upBath

	//Ogre::Entity* ent3 = mSM->createEntity("RomanBathUpper.mesh");
	//mRBUpper = mSM->getRootSceneNode()->createChildSceneNode("nRBUpper");
	//mRBUpper->attachObject(ent3);

	//// Show bounding box
	//mRBUpper->showBoundingBox(true);

	//// Set scale of Sword
	//mRBUpper->setScale(1, 1, 1);

	////------------------------------------------------------------------------
	//// Creating Coljums

	//Ogre::Entity* ent4 = mSM->createEntity("Columns.mesh");
	//mColums = mSM->getRootSceneNode()->createChildSceneNode("nColumns");
	//mColums->attachObject(ent4);

	//// Show bounding box
	//mColums->showBoundingBox(true);

	// Set scale of Sword
	//mColums->setScale(1, 1, 1);

	laberinto = new Labyrinth(LABERINTO1, mSM->getRootSceneNode(), mSM);


}


