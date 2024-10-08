#pragma once

#include "IG2Object.h"

class Hero : public IG2Object
{
private:

	float speed = 1;
	Vector3 direction{ 0,0,0 };

	Vector2 labPos;

public:

	Hero() : IG2Object() {}
	Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "sinbad.mesh", string name = "hero");
	~Hero();

	void init() override {}

	void frameRendered(const Ogre::FrameEvent& evt) override;
	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;

	void rotate();
};