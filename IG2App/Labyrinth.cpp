
#include "Labyrinth.h"

using namespace std;

Labyrinth::Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan)
{
	ifstream archivo(root);

	if (!archivo.is_open()) {
		cout << "NO SE HA ABIERTO EL ARCHIVO" << endl;
		return;
	}

	archivo >> nFilas;
	archivo >> nColumnas;



	std::vector<string> filas;

	for (int i = 0; i < nFilas; i++)
	{
		string fila = " ";
		archivo >> fila;
		filas.push_back(fila);
	}

	int cont = 0;
	int nEnemies = 0;
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
			Block* obj = nullptr;
			Enemy* ene = nullptr;

			switch (filas[i][j])
			{
			case 'x':
				obj = new Wall({ 0, 0, 0 }, sNode, sCMan, "cube.mesh", "Wall" + to_string(i * nColumnas + j));

				if (boxSize == Vector3{ 0, 0, 0 })
					boxSize = obj->calculateBoxSize();

				break;
			case 'o':
				obj = new Pearl({ 0, 0, 0 }, sNode, sCMan, "sphere.mesh", "Pearl" + to_string(i * nColumnas + j));

				obj->setScale({ .2, .2, .2 });

				break;
			case 'h':
				hero = new Hero({ 0, 0, 0 }, sNode, sCMan, this);

				hero->setScale({ 15, 15, 15 });

				hero->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });

				break;
			case 'v':
				ene = new Enemy({ 0, 0, 0 }, sNode, sCMan, "Enemy" + to_string(nEnemies), this);
				nEnemies++;
				enemies.push_back(ene);
				ene->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });
				break;
			case 'V':
				ene = new MasterEnemy({ 0, 0, 0 }, sNode, sCMan, "MasterEnemy" + to_string(nEnemies), this);
				nEnemies++;
				enemies.push_back(ene);
				ene->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });
				break;
			default:
				obj = nullptr;
				ene = nullptr;
				break;
			}

			objs.push_back(obj);

			if (obj == nullptr)
				continue;

			obj->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });


			cont++;
		}
	}

	archivo.close();
}

Labyrinth::~Labyrinth()
{

}

bool Labyrinth::checkDirection(Vector3 dir)
{
	Vector3 posHero = (hero->getPosition()) / boxSize; // Posicion en el laberinto normalizado.


	int id = trunc(posHero.z) * nColumnas + trunc(posHero.x);

	//if (objs[id] == nullptr) return true; // Para cuando pase por la poscion donde aparece el personaje.
	/*
	Vector3 boxCentrePos = objs[id]->getPosition() + Vector3(boxSize.x / 2, 0, boxSize.z / 2);
	if (hero->getPosition() == boxCentrePos) {
		cout << "ONCENTRE" << endl;
		return false;
	}*/

	if (dir == Vector3(1, 0, 0) || dir == Vector3(0, 0, 1))
		posHero += dir;

	id = trunc(posHero.z) * nColumnas + trunc(posHero.x);
	//cout << "Check Direction" << endl;
	if (objs[id] == nullptr) return true; // Para cuando pase por la poscion donde aparece el personaje.

	if (objs[id]->getType() != BLOCK_TYPE::WALL)
		return true;
	return false;
}

float Labyrinth::getDistanceWithHero(Vector3 otherPos)
{
	Vector3 heroPos = hero->getPosition();

	return std::sqrt(
		std::pow(otherPos.x - heroPos.x, 2) +
		std::pow(otherPos.y - heroPos.y, 2) +
		std::pow(otherPos.z - heroPos.z, 2));
}

Vector3 Labyrinth::getDirection(Enemy* ene)
{
	Vector3 newDIr;
	Vector3 enemyPos = ene->getPosition();


	Vector3 aux1 = enemyPos + Vector3(1, 0, 0);
	float dis1 = getDistanceWithHero(aux1);

	Vector3 aux2 = enemyPos + Vector3(-1, 0, 0);
	float dis2 = getDistanceWithHero(aux2);

	Vector3 aux3 = enemyPos + Vector3(0, 0, 1);
	float dis3 = getDistanceWithHero(aux3);

	Vector3 aux4 = enemyPos + Vector3(0, 0, -1);
	float dis4 = getDistanceWithHero(aux4);

	if (dis4 > dis1 && dis4 > dis2 && dis4 > dis3)
	{
		return { 0, 0, -1 };
	}
	else if (dis3 > dis1 && dis3 > dis2 && dis3 > dis4)
	{
		return { 0, 0, 1 };
	}
	else if (dis2 > dis1 && dis2 > dis3 && dis2 > dis4)
	{
		return { -1, 0, 0 };
	}
	else if (dis1 > dis2 && dis1 > dis3 && dis1 > dis4)
	{
		return { 1, 0, 0 };
	}
}