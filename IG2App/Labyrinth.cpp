
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
			Block* obj = nullptr; // Que sea de tipo bloque para los enemigos no sirve...
			Enemy* ene = nullptr; // Mal?

			switch (filas[i][j])
			{
			case 'x':
				obj = new Wall({ 0, 0, 0 }, sNode, sCMan, "cube.mesh", "Wall" + to_string(i * nColumnas + j));

				if (boxSize == Vector3{ 0, 0, 0 })
					boxSize = obj->calculateBoxSize();

				break;
			case 'o':
				obj = new Pearl({ 0,0,0 }, sNode, sCMan, "sphere.mesh", "Pearl" + to_string(i * nColumnas + j));

				obj->setScale({ .2, .2, .2 });

				break;
			case 'h':
				hero = new Hero({ 0,0,0 }, sNode, sCMan, "Sinbad.mesh", "Wall" + to_string(i * nColumnas + j), this);

				hero->setScale({ 15, 15, 15 });

				hero->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });

				break;
			case 'v':
				//ene = new Enemy({ 0, 0, 0 }, sNode, sCMan, "ogrehead.mesh", "Enemy" + to_string(nEnemies),this);
				// PAIGRO AQUI: se tiene que hacer de otra forma lo del ene.
				nEnemies++;
				break;
			case 'V':

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