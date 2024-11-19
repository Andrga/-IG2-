#pragma once
#include "Character.h"

class HeroIntro : public Character
{
public:
	HeroIntro();
	~HeroIntro();

	void frameRendered(const Ogre::FrameEvent& evt) override;
};

