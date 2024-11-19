#pragma once

#include "Character.h"

class Labyrinth;


class Hero : public Character
{
private:

	bool invincible = false;
	Ogre::Timer* timer;
	float timeinvincible = 5;

public:

	Hero() : Character() {}
	Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, Labyrinth* lab = nullptr);
	~Hero();
	bool keyPressed(const OgreBites::KeyboardEvent& evt) override;

	bool getInvincible() { return invincible; }
	void setInvincible() { 		invincible = true; };

	// Sobre carga del frameRenderer que hace de Update.
	//void frameRendered(const Ogre::FrameEvent& evt) override;
	void update()override;
};