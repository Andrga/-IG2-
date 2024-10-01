#pragma once

#include "IG2Object.h"

class Pearl : public IG2Object
{
private:





public:

	Pearl() : IG2Object() {}
	Pearl(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "sphere.mesh");
	~Pearl();

	void init() override {}

};

