
#include "Labyrinth.h"

using namespace std;

Labyrinth::Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan, IG2Object* hero)
{
	ifstream archivo(root);

	if (!archivo.is_open()) {
		cout << "NO SE HA ABIERTO EL ARCHIVO" << endl;
		return;
	}

	int nFilas = 0, nColumnas = 0;

	archivo >> nFilas;
	archivo >> nColumnas;

	std::vector<string> filas;

	/*for (auto f : filas)
	{
		archivo >> f;
	}*/
	for (int i = 0; i < nFilas; i++)
	{
		string fila = " ";
		archivo >> fila;
		filas.push_back(fila);
	}

	int cont = 0;
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
			if (filas[i][j] == 'x')
			{

			}
			else if (filas[i][j] == 'o')
			{

			}
			IG2Object* obj = nullptr;

			switch (filas[i][j])
			{
			case 'x':
				obj = new Wall({ 0, 0, 0 }, sNode, sCMan, "cube.mesh", "Wall" + to_string(i * nColumnas + j));
				if (boxSize == Vector3{ 0, 0, 0 })
				{
					boxSize = obj->calculateBoxSize();
				}

				break;
			case 'o':
				obj = new Pearl({ 0,0,0 }, sNode, sCMan, "sphere.mesh", "Pearl" + to_string(i * nColumnas + j));

				obj->setScale({ .2, .2, .2 });

				break;
			case 'h':
				obj = new Hero({ 0,0,0 }, sNode, sCMan, "Sinbad.mesh", "Wall" + to_string(i * nColumnas + j));

				obj->setScale({ 15, 15, 15 });

				obj->addListener(obj);
				hero = obj;
				break;
				/*case 'x':
					break;*/
			default:
				obj = nullptr;
				break;
			}

			obj->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });

			objs.push_back(obj);

			cont++;
		}
	}

	archivo.close();
}

Labyrinth::~Labyrinth()
{

}
