#pragma once

#include "Character.h"

class Labyrinth;


class Hero : public Character
{
private:

	float speed = 1;
	Vector3 direction{ 0,0,1 };
	Vector3 rotateDirection{ 0,0,1 };

	Vector2 labPos;

	Labyrinth* laberynth;

public:

	Hero() : Character(), laberynth(nullptr) {}
	Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~Hero();
	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
};