#pragma once
#include "fstream"

#include "IG2Object.h"

#include <OgreParticleSystem.h>

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

	Ogre::SceneManager* sMang = nullptr; // Referencia al SceneManager.

	SceneNode* gameNode; // Referencia al sceneNode en el que esta el laberinto.

	SceneNode* camNode; // Renferencia al nodo de la camara.

	std::vector<std::vector<Block*>> objs; // Vector de bloques.
	std::vector<Enemy*> enemies; // Vector de enemigos, incluye el master enemy.
	Hero* hero = nullptr; // Referencia al heroe.

	SceneNode* nGround = nullptr; // Referencia al nodo del suelo.

	Vector3 boxSize = { 0, 0, 0 }; // Tamanyo del bloque.

	int nFilas = 0; // Filas del laberinto.
	int nColumnas = 0; // Columnas del laberinto.

	char lightType = ' '; // Char para guardar el tipo de luz segun se lea del archivo.
	Ogre::SceneNode* mLightNode = nullptr; // Referencia al nodo de la luz.
	bool lightMoves = false; // Si la luz es de tipo spot entonces se mueve con el jugador, sino no.

	int maxPoints; // Maximo de puntos del nivel dependiendo de las perlas leidas del txt.
	int actualPoints = 0; // Puntos que lleva el jugador.

	std::vector<ParticleSystem*> vParSys; // Vector de sistemas de particulas de humo.

public:

	//------Constructoras y destructoras:

	// Constructora base de Labyrinth.
	Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan, SceneNode* cNode);
	// Destructora de Labyrinth.
	~Labyrinth();


	//------Metodos de la escena:

	// Update del labertinto.
	void update(const Ogre::FrameEvent& evt);
	// Hace el nivel visible o invisible.
	void setVisible(bool vis);


	//------Getters y setters:

	// Gettea el heroe.
	Hero* getHero() { return hero; }
	// Gettea el vector de enemigos.
	std::vector<Enemy*> getEnemies() { return enemies; }
	// Devuelve el bloque que hay frente a pos en la direccion dir.
	Block* getBlock(Vector3 pos, Vector3 dir);


	//------Metodos sobre el movimiento de entidades:

	// Devuelve si se puede mover en esa direccion (si hay una pared o no).
	bool checkDirectionAvailable(Character* charac, Vector3 dir);
	// Devuelve la distancia entre un enemigo y el hero.
	float getDistanceWithHero(Vector3 enemyPos);
	// Devuelve la siguiente direccion del enemigo dependiendo de su proximidad al heroe.
	Vector3 getDirection(Enemy* ene);


	//------Metodos de colisiones:

	// Comprueba la colion entre el heroe y los enemigos.
	bool checkEnemyCollision();


	//------Metodos sobre el laberinto:

	// Crea el plano del suelo.
	void createGround(SceneManager* sCMan, string matFloor);
	// Devuelve el centro del laberinto.
	Vector3 getCenter();


	//------Metodos sobre la victoria y la vida del heroe:

	// Cuando te comes una perla.
	void eatPerl(Block* bloq);
	// Devuelve los puntos actuales.
	int getPoints() { return actualPoints; };
	// Devuelve el maximo de puntos del nivel dependiendo del numero de perlas cargadas del txt.
	int getMaxPoints() { return maxPoints; };
	// Vuelve invulnerable al heroe tras haber colisionado con un enemigo.
	void setInvulnerable();


	//------Metodos sobre luces:

	// Crea la luz dependiendo del tipo leido del archivo.
	void createLight(SceneManager* sCMan, char t);
	// Actualiza la poscion de la luz.
	void updateLight();
};