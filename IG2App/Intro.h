#pragma once

#include "fstream"

#include "IG2Object.h"
#include "string"
#include "Character.h"

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



public:

	Intro(SceneManager* SM,  SceneNode* sNode);
	~Intro();

	void setUpScene();
	void setVisible(bool vis);

};