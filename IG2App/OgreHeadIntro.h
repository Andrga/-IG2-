#pragma once
#include "Character.h"

class OgreHeadIntro: public Character
{
public:
	OgreHeadIntro();
	~OgreHeadIntro();

	void frameRendered(const Ogre::FrameEvent& evt) override;
};

