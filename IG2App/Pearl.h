#pragma once

#include "Block.h"

class Pearl : public Block
{
private:





public:

	Pearl() : Block() {}
	Pearl(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "sphere.mesh", string name = "pearl");
	~Pearl();

	void init() override {}

	
};

