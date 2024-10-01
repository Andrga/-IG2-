#pragma once
#include "fstream"

#include "IG2Object.h"
#include "string"
#include "Wall.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

const float LADO_CUBO = 10;

class Labyrinth
{
private:
	vector<IG2Object> objs;

public:
	Labyrinth(string root);

	~Labyrinth();




};

