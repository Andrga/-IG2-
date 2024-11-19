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

	std::vector<std::vector<Block*>> objs; // Vector de bloques.
	std::vector<Enemy*> enemies; // Vector de enemigos, incluye el master enemy.
	Hero* hero = nullptr; // Referencia al heroe.

	Vector3 boxSize = { 0, 0, 0 };

	int nFilas = 0; // Filas del laberinto.
	int nColumnas = 0; // Columnas del laberinto.

	SceneNode* gameNode; // Referencia al sceneNode en el que esta el laberinto.
	Ogre::SceneNode* mLightNode = nullptr;
	bool lightMoves = false;

	// puntos para ganar
	int maxPoints;
	int actualPoints = 0;

	char lightType = ' '; // Char para guardar el tipo de luz segun se lea del archivo.

public:

	//------Constructoras y destructoras:

	// Constructora base de Labyrinth.
	Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan, SceneNode* cNode);
	// Destructora de Labyrinth.
	~Labyrinth();


	//------Getters y setters:

	// Gettea el heroe.
	Hero* getHero() { return hero; }
	std::vector<Enemy*> getEnemies() { return enemies; }
	Block* getBlock(Vector3 pos, Vector3 dir);


	//------Metodos sobre el movimiento de entidades:

	// Devuelve si se puede mover en esa direccion (si hay una pared o no)
	bool checkDirectionAvailable(Character* charac, Vector3 dir);
	// Devuelve la distancia entre un enemigo y el hero.
	float getDistanceWithHero(Vector3 enemyPos);
	// 
	Vector3 getDirection(Enemy* ene);

	void update();


	//------Metodos de colisiones:

	// Comprueba la colion entre el heroe y los enemigos.
	bool checkEnemyCollision();


	//------Metodos sobre el laberinto:

	// Crea el plano del suelo.
	void createGround(SceneManager* sCMan, string matFloor);
	//
	Vector3 getCenter();


	//------Metodos sobre la victoria y la vida del heroe:

	//
	void eatPerl(Block* bloq);
	//
	int getPoints() { return actualPoints; };
	//
	int getMaxPoints() { return maxPoints; };
	// Vuelve invulnerable al heroe tras haber colisionado con un enemigo.
	void setInvulnerable();


	//------Metodos sobre luces:

	// Crea la luz dependiendo del tipo leido del archivo.
	void createLight(SceneManager* sCMan, char t);
	// Actualiza la poscion de la camara si toda.
	void updateLight();

	void setVisible(bool vis);
};