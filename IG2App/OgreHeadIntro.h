#pragma once
#include "Character.h"

class OgreHeadIntro: public Character
{
public:
	OgreHeadIntro();
	~OgreHeadIntro();

	void update() override;
};