#pragma once

#include "fstream"

#include "IG2Object.h"
#include "string"
#include "HeroIntro.h"
#include "OgreHeadIntro.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


class Intro
{
private:

	std::vector<Character*> actors;

	SceneNode* introNode = nullptr;
	SceneManager* sMang = nullptr;
	
	Camera* introCamera = nullptr;

	Light* introLight = nullptr;

	HeroIntro* hero = nullptr;
	OgreHeadIntro* head = nullptr;

	Ogre::Light* light = nullptr;

public:

	Intro(SceneManager* SM,  SceneNode* sNode);
	~Intro();

	void setUpScene();
	void setVisible(bool vis);


	void update();
};