
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

	std::vector<string> filas(nFilas);

	for (auto f : filas)
	{
		archivo >> f;
	}

	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
			if (filas[nColumnas * i + j] == "x")
			{
				objs.push_back(new Wall({ i * LADO_CUBO,j * LADO_CUBO,0 }, _sNode, _sCMan));
			}
			else if (filas[nColumnas * i + j] == "o")
			{
				objs.push_back(new Pearl({ i * LADO_CUBO,j * LADO_CUBO,0 }, _sNode, _sCMan));
			}
		}
	}





}

Labyrinth::~Labyrinth()
{

}
