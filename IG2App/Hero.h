#pragma once

#include "IG2Object.h"

class Labyrinth;


class Hero : public IG2Object
{
private:

	float speed = 1;
	Vector3 direction{ 0,0,1 };
	Vector3 rotateDirection{ 0,0,1 };

	Vector2 labPos;

	Labyrinth* laberynth;

public:

	Hero() : IG2Object() {}
	Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh = "sinbad.mesh", string name = "hero", Labyrinth* lab = nullptr);
	~Hero();

	void init() override {}

	void frameRendered(const Ogre::FrameEvent& evt) override;
	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;

	void rotate();
};