#include "Labyrinth.h"

void Labyrinth::init()
{
	for (size_t i = 0; i < 3; i++)
	{
		SceneNode wal();
		Ogre::Vector3 pos(i * 10.0, 0.0, 0.0);
		Wall wall(pos , wal, mSM);
		mNode->addChild(new)
	}
}
