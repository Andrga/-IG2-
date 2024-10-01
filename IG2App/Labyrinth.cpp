
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


	/*for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
			if (filas[i][j] == 'x')
			{
				IG2Object* object = nullptr;
				object = new Wall({ (float)i, (float)j, 0 }, _sNode, _sCMan);
				Vector3 v = object->calculateBoxSize();
				object->setPosition({ i * v.x,j * v.y , 0 });
				objs.push_back(object);
			}
			else if (filas[i][j] == 'o')
			{
				//objs.push_back(new Pearl({ (float)i, (float)j, 0 }, _sNode, _sCMan));
			}
		}
	}*/
	for (int i = 0; i < 100; i++)
	{
		IG2Object* object = nullptr;
		object = new Wall({ 0, 0, 0 }, _sNode, _sCMan);
		Vector3 v = object->calculateBoxSize();
		object->setScale(v * 5);
		object->setPosition({ i * v.x, 0 , 0 });
		//objs.push_back(object);
	}

	archivo.close();
}

Labyrinth::~Labyrinth()
{

}
