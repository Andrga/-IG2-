#pragma once
#include "fstream"

#include "IG2Object.h"
#include "string"


#include "Wall.h"
#include "Pearl.h"
#include "Hero.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

class Labyrinth
{
private:
	std::vector<IG2Object*> objs;

	Vector3 boxSize = { 0,0,0 };

	SceneNode* sNode;
public:
	Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan, IG2Object* hero);

	~Labyrinth();




};

