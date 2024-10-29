#pragma once
#include "fstream"

#include "IG2Object.h"
#include "string"


#include "Wall.h"
#include "Pearl.h"
#include "Hero.h"
#include "Enemy.h"
#include "MasterEnemy.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


class Labyrinth
{
private:

	std::vector<Block*> objs; // Vector de bloques.
	std::vector<Enemy*> enemies; // Vector de enemigos, incluye el master enemy.
	Hero* hero = nullptr; // Referencia al heroe.

	Vector3 boxSize = { 0, 0, 0 };

	int nFilas = 0; // Filas del laberinto.
	int nColumnas = 0; // Columnas del laberinto.

	SceneNode* sNode; // Referencia al sceneNode en el que esta el laberinto.

public:

	//------Constructoras y destructoras:

	// Constructora base de Labyrinth.
	Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan);
	// Destructora de Labyrinth.
	~Labyrinth();

	//------Getters y setters:

	// Gettea el heroe.
	Hero* getHero() { return hero; }


	//------Metodos sobre el movimiento de entidades:

	// Devuelve si se puede mover en esa direccion (si hay una pared o no)
	bool checkDirection(Vector3 dir);
};