#pragma once

#include "Block.h"

class Wall : public Block
{
private:


public:
	Wall() : Block() {}
	Wall(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "cube.mesh", string name = "wall");
	void init() override {}

};