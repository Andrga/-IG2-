#include "Block.h"

Block::Block(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh)
:IG2Object(initPos,node , sceneMng, mesh)
{

}

Block::~Block()
{
}

BLOCK_TYPE Block::getType()
{
	return blockType;
}
