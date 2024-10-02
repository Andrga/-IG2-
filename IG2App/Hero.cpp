#include "Hero.h"

Hero::Hero(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, String mesh, string name)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng, mesh)
{}

Hero::~Hero()
{

}

bool Hero::keyPressed(const OgreBites::KeyboardEvent& evt)
{

	mNode->translate(0, 0, speed);
	std::cout << "movimiento" << std::endl;

	return false;
	/*switch (key)
	{
	case SDLK_UP:
		setPosition(getPosition() + Vector3{ 0, 0, speed });
		getOrientation();
		break;
	case SDLK_DOWN:
		setPosition(getPosition() + Vector3{ 0, 0, -speed });
		break;
	case SDLK_LEFT:
		setPosition(getPosition() + Vector3{ -speed, 0, 0 });
		break;
	case SDLK_RIGHT:
		setPosition(getPosition() + Vector3{ speed, 0, 0 });
		break;
	default:
		break;
	}*/
}
