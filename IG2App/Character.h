#pragma once

#include "IG2Object.h"

class Labyrinth;


class Character : public IG2Object
{
private:

	float speed = 1;
	Vector3 direction{ 0,0,1 };
	Vector3 rotateDirection{ 0,0,1 };

	Vector2 labPos;

	Labyrinth* laberynth = nullptr;

public:

	Character() : IG2Object(), laberynth(nullptr) {}
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name = "hero", Labyrinth* lab = nullptr);
	~Character();

	void init() override {}

	void frameRendered(const Ogre::FrameEvent& evt) override;
	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
	void setDirection(Vector3 newDir);

	void rotate();
};