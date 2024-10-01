
#include "Labyrinth.h"

using namespace std;

Labyrinth::Labyrinth(string root)
{
	ifstream archivo(root);

	if (!archivo.is_open()) {
		cout << "NO SE HA ABIERTO EL ARCHIVO" << endl;
	}

	int nFilas = 0, nColumnas = 0;

	archivo >> nFilas;
	archivo >> nColumnas;

	vector<string> filas;

	for (int i = 0; i < nColumnas; i++)
	{
		string e;

		archivo >> e;
		filas.push_Back(e);
	}
}

Labyrinth::~Labyrinth()
{

}
