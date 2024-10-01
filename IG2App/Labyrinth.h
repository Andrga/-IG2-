#pragma once
#include "fstream"

#include "IG2Object.h"
#include "string"


#include "Wall.h"
#include "Pearl.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

const float LADO_CUBO = 10;

class Labyrinth
{
private:
	std::vector<IG2Object*> objs;

	SceneNode* sNode;
public:
	Labyrinth(string root, SceneNode* _sNode, SceneManager* _sCMan);

	~Labyrinth();




};

