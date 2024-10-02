#pragma once

#include "IG2Object.h"

class Hero : public IG2Object
{
private:

	float speed = 50.0;

public:

	Hero() : IG2Object() {}
	Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "sinbad.mesh", string name = "hero");
	~Hero();

	void init() override {}


	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
};