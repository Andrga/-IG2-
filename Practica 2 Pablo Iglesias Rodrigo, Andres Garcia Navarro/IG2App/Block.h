#pragma once

#include "IG2Object.h"

enum BLOCK_TYPE
{
	WALL,
	PEARL
};

class Block : public IG2Object
{
protected:

	BLOCK_TYPE blockType;
	bool visible = true;


public:

	Block() : IG2Object() {}
	Block(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh);
	~Block();

	BLOCK_TYPE getType();

	void setVisible(bool vis) override {
		visible = vis;
		IG2Object::setVisible(vis);
	}
	bool getVisible() { return visible; }

};