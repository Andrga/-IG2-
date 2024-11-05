#pragma once

#include "IG2Object.h"

class Labyrinth;


class Character : public IG2Object
{
protected:
	Vector3 direction{ 0,0,0 };
	Vector3 rotateDirection{ 0,0,0 };
	Labyrinth* laberynth = nullptr;

public:

	Character() : IG2Object(), laberynth(nullptr) {}
	Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name = "hero", Labyrinth* lab = nullptr);
	~Character();

	void init() override {}

	virtual void frameRendered(const Ogre::FrameEvent& evt) override;
	bool isCenter();

	void rotate();
};