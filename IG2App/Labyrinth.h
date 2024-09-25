#pragma once

#include "IG2Object.h"
#include "Wall.h"

class Labyrinth : public IG2Object
{
public:
	Labyrinth() : IG2Object() {}

	Labyrinth(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh) : IG2Object(initPos, node, sceneMng, mesh) {}

	void init() override;




};

