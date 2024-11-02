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
	if (isCenter() && laberynth->checkDirection(this, direction)) {
		//cout << "HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA SOY INEPRIMO" << endl;
		direction = rotateDirection;
		rotate();


	}

	//mNode->translate(Vector3{ 0, 0, 1 }, Ogre::Node::TransformSpace::TS_LOCAL);
	mNode->translate(direction);

}

void Character::setDirection(Vector3 newDir)
{

	if (newDir != direction) {

		direction = newDir;

		//cout << " is cneter? ??¿?¿¿????????????????¿¿?¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¡¡¡¡" << newDir << endl;

		/*if (laberynth->checkDirection(this, rotateDirection))
			*/
		//cout << direction << endl;
		rotate();

	}
}

bool Character::isCenter()
{
	int x, y, z;
	x = mNode->getPosition().x;
	y = mNode->getPosition().y;
	z = mNode->getPosition().z;

	Vector3 centro(x % 98, y % 98, z % 98);

	//Si todos los numeros son multiplos de 100 esta en un centro
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
