#pragma once
#include "fstream"

#include "IG2Object.h"
#include "string"


#include "Wall.h"
#include "Pearl.h"
#include "Hero.h"
#include "Enemy.h"
#include "MasterEnemy.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

class Labyrinth
{
private:
	std::vector<Block*> objs;
	Hero* hero = nullptr;
	Vector3 boxSize = { 0,0,0 };

	int nFilas = 0;
	int nColumnas = 0;

	SceneNode* sNode;
public:
	Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan);
	~Labyrinth();

	Hero* getHero() { return hero; }

	bool checkDirection(Vector3 dir);
};

