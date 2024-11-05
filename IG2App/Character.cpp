#include "Character.h"
#include "Labyrinth.h"

Character::Character(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, string name, Labyrinth* lab)
	: IG2Object(initPos, node->createChildSceneNode(name), sceneMng), laberynth(lab)
{

}

Character::~Character()
{
}

void Character::frameRendered(const Ogre::FrameEvent& evt)
{
	if (isCenter()) {
		if (rotateDirection != direction && laberynth->checkDirectionAvailable(this, rotateDirection)) {
			rotate();
			//cout << "rota" << endl;
		}
		if (!laberynth->checkDirectionAvailable(this, direction)) {
			direction = Vector3(0, 0, 0);
			//cout << "No puede andar" << endl;
		}
	}


	if (direction != Vector3(0, 0, 0))
	{
		mNode->translate(direction);
		//cout << "ANDA" << endl;
		//cout << direction << endl;
	}

}

bool Character::isCenter()
{
	int x, y, z;
	x = mNode->getPosition().x;
	y = mNode->getPosition().y;
	z = mNode->getPosition().z;

	Vector3 centro(x % 98, y % 98, z % 98);

	//Si todos los numeros son multiplos de 98 esta en un centro
	if (centro == Vector3().ZERO)
		return true;
	return false;
}

void Character::rotate()
{
	Quaternion q = this->getOrientation().getRotationTo(rotateDirection);
	mNode->rotate(q);
	direction = rotateDirection;
}
