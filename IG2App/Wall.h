#pragma once

#include "IG2Object.h"

class Wall : public IG2Object
{
private:


public:
	Wall() : IG2Object() {}
	Wall(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "cube.mesh", string name = "wall");
	void init() override {}

};

