
#include "Labyrinth.h"

using namespace std;

Labyrinth::Labyrinth(string root, SceneNode* _sNode, SceneManager* _sCMan)
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
				auto w = new Wall({ 0,0,0 }, _sNode, _sCMan, "cube.mesh", "Wall" + to_string(i * nColumnas + j));
				if (boxSize == Vector3{0, 0, 0}) {
					boxSize = w->calculateBoxSize();

				}

				w->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });

				objs.push_back(w);
			}
			else if (filas[i][j] == 'o')
			{
				auto w = new Pearl({ 0,0,0 }, _sNode, _sCMan, "sphere.mesh", "Pearl" + to_string(i * nColumnas + j));
				w->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });

				w->setScale({ .2,.2,.2 });

				objs.push_back(w);
			}

			cont++;
		}
	}

	archivo.close();
}

Labyrinth::~Labyrinth()
{

}
