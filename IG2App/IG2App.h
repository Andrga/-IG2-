#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>
#include <sstream>
#include <iostream>
#include <string>


#include "Labyrinth.h"


const string LABERINTO1 = "../Labyrinths/stage1.txt";
const string LABERINTO2 = "../Labyrinths/stage2.txt";



class IG2App : public  OgreBites::IG2ApplicationContext, OgreBites::InputListener {

public:
	explicit IG2App() : IG2ApplicationContext("IG2App") { };  // new -> setup()
	virtual ~IG2App() { };                                    // delete -> shutdown()

	void nextLaberynth();

	void createLight();

protected:
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
	virtual void setup();
	virtual void shutdown();
	virtual void setupScene();
	bool frameEnded(const Ogre::FrameEvent& evt) override;


	Ogre::SceneNode* mSinbad = nullptr;
	Ogre::SceneNode* mColums = nullptr;
	Ogre::SceneNode* mRBUpper = nullptr;
	Ogre::SceneNode* mRBLower = nullptr;

	Labyrinth* laberinto = nullptr;

	Ogre::SceneManager* mSM = nullptr;
	OgreBites::TrayManager* mTrayMgr = nullptr;

	Ogre::Light* light = nullptr;
	Ogre::SceneNode* mLightParent = nullptr;
	Ogre::SceneNode* mLightNode = nullptr;

	Ogre::SceneNode* mCamNode = nullptr;
	OgreBites::CameraMan* mCamMgr = nullptr;

	IG2Object* hero = nullptr;
	// Informacion del nivel
	int lives = 10;

	// UI nivel
	OgreBites::Label* label;
	OgreBites::TextBox* textBox;

	bool lightMoves = false;
};

#endif