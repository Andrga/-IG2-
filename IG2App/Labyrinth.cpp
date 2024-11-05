
#include "Labyrinth.h"

using namespace std;

Labyrinth::Labyrinth(string root, SceneNode* sNode, SceneManager* sCMan)
{
	ifstream archivo(root);

	if (!archivo.is_open()) {
		cout << "NO SE HA ABIERTO EL ARCHIVO" << endl;
		return;
	}
	string wallMat, perlMat, flootMat;
	archivo >> wallMat >> perlMat >> flootMat;

	archivo >> nFilas;
	archivo >> nColumnas;

	archivo >> lightType;


	std::vector<string> filas;

	for (int i = 0; i < nFilas; i++)
	{
		string fila = " ";
		archivo >> fila;
		filas.push_back(fila);
	}

	int cont = 0;
	int nEnemies = 0;
	std::vector<Block*> auxBloq;
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
			Block* obj = nullptr;
			Enemy* ene = nullptr;

			switch (filas[i][j])
			{
			case 'x':
				obj = new Wall({ 0, 0, 0 }, sNode, sCMan, wallMat, "cube.mesh", "Wall" + to_string(i * nColumnas + j));

				if (boxSize == Vector3{ 0, 0, 0 })
					boxSize = obj->calculateBoxSize();

				break;
			case 'o':
				obj = new Pearl({ 0, 0, 0 }, sNode, sCMan, perlMat, "sphere.mesh", "Pearl" + to_string(i * nColumnas + j));

				obj->setScale({ .2, .2, .2 });
				maxPoints++;

				break;
			case 'h':
				hero = new Hero({ 0, 0, 0 }, sNode, sCMan, this);

				hero->setScale({ 15, 15, 15 });
				cout << objs.size() << endl;
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

			auxBloq.push_back(obj);

			if (obj == nullptr)
				continue;

			obj->setPosition({ (boxSize.x * j) , 0, (boxSize.x * i) });


			cont++;
		}
		objs.push_back(auxBloq);
		auxBloq.clear();
	}

	createGround(sCMan, flootMat); // Se crea el suelo.
	createLight(sCMan, lightType);

	archivo.close();
}

Labyrinth::~Labyrinth()
{
	delete hero;
	hero = nullptr;

	for (auto o : objs)
	{
		for (auto b : o)
		{
			delete b;
			b = nullptr;
		}
	}
	objs.clear();

	for (auto e : enemies)
	{
		delete e;
		e = nullptr;
	}
	enemies.clear();

	delete sNode;
	sNode = nullptr;

	delete mLightNode;
	mLightNode = nullptr;
}

bool Labyrinth::checkDirection(Character* charac, Vector3 dir)
{
	int idx = trunc((charac->getPosition().x) / 98) + dir.x;
	int idy = trunc((charac->getPosition().z) / 98) + dir.y;


	if (idy >= nColumnas || idx >= nFilas)
		return false;
	else if (objs[idy][idx] == nullptr)
		return true;

	//cout << "x: " << idx << " z: " << idy << endl;
	if (charac == hero && objs[idy][idx]->getType() == 1 && objs[idy][idx]->getVisible())
		eatPerl(idy, idx);

	if (charac == hero)
		cout << objs[idx][idy]->getType() << endl;
	return  objs[idx][idy]->getType() != 0;
}

float Labyrinth::getDistanceWithHero(Vector3 otherPos)
{
	Vector3 heroPos = hero->getPosition();

	return std::sqrt(
		std::pow(otherPos.x - heroPos.x, 2) +
		std::pow(otherPos.z - heroPos.z, 2));
}

Vector3 Labyrinth::getDirection(Enemy* ene)
{
	std::vector<Vector3> dirs;
	Vector3 enemyPos = ene->getPosition();
	// Cogemos las direcciones validas
	if (checkDirection(ene, { 0,0,1 })) {
		dirs.push_back({ 0,0,1 });
	}
	if (checkDirection(ene, { 0,0,-1 })) {
		dirs.push_back({ 0,0,-1 });
	}
	if (checkDirection(ene, { 1,0,0 })) {
		dirs.push_back({ 1,0,0 });
	}
	if (checkDirection(ene, { -1,0,0 })) {
		dirs.push_back({ -1,0,0 });
	}
	//cout << "DirsSize: " << dirs.size() << endl;
	// comprobamos de todas las direcciones validas la mas cercana al heroe
	Vector3 newDir;
	float minDist = -10;

	for (int i = 0; i < dirs.size(); i++)
	{
		float auxdist = getDistanceWithHero(enemyPos + dirs[i]);
		if (minDist < 0 || auxdist <= minDist) {
			minDist = auxdist;
			newDir = dirs[i];
		}
	}
	//cout << newDir << endl;
	return newDir;
}

bool Labyrinth::checkCollision()
{
	if (hero->getInvincible())
		return false;

	AxisAlignedBox eBox; // AAB del enemigo que toque.
	AxisAlignedBox hBox = hero->getAABB(); // AAB del heroe.
	bool collision = false; // Si ha habido colision o no.

	int i = 0;
	while (!collision && i < enemies.size())
	{
		eBox = enemies[i]->getAABB();

		if (hBox.intersects(eBox)) { collision = true; }

		i++;
	}

	return collision;
}

void Labyrinth::createGround(SceneManager* sCMan, string matFloor)
{
	Plane ground(Vector3::UNIT_Y, 0); // Plano con orientacion.

	Ogre::MeshManager::getSingleton().createPlane(
		"ground", // Nombre de la nueva mesh.
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, // Grupo.
		ground, // Plano base.
		boxSize.x * nColumnas, boxSize.z * nFilas, // Tamanyo.
		20, 20, // Segmentos.
		true, 1, // Normales y numTexCoordSet.
		5, 5, // repeticiones de la textura.
		Vector3::UNIT_Z); // Orientacion.

	Entity* eGround = sCMan->createEntity("suelo", "ground");
	SceneNode* nGround = sCMan->getRootSceneNode()->createChildSceneNode("groundNode");
	nGround->attachObject(eGround);

	nGround->setPosition(Vector3(
		((boxSize.x * nColumnas) / 2) - (boxSize.x / 2),  // X ajustada.
		-boxSize.y / 2, // Y ajustada.
		((boxSize.z * nFilas) / 2) - (boxSize.z / 2))); // Z ajustada.
	eGround->setMaterialName(matFloor); // set material
}

Vector3 Labyrinth::getCenter()
{
	return Vector3(
		((boxSize.x * nColumnas) / 2) - (boxSize.x / 2),  // X ajustada.
		-boxSize.y / 2, // Y ajustada.
		((boxSize.z * nFilas) / 2) - (boxSize.x / 2)); // Z ajustada.
}

void Labyrinth::eatPerl(int idx, int idz)
{
	objs[idx][idz]->setVisible(false);
	actualPoints++;
}

void Labyrinth::setInvulnerable()
{
	hero->setInvincible();
}

void Labyrinth::createLight(SceneManager* sCMan, char t)
{
	Light* luz = sCMan->createLight("Luz");

	switch (toupper(t))
	{
	case 'D': // Luz direccional
		std::cout << "Luz direccional." << std::endl;
		luz->setType(Ogre::Light::LT_DIRECTIONAL);
		break;

	case 'S': // Luz spot.
		std::cout << "Luz spot." << std::endl;
		luz->setType(Ogre::Light::LT_SPOTLIGHT);
		lightMoves = true;
		break;

	case 'P': // Luz point.
		std::cout << "Luz point." << std::endl;
		luz->setType(Ogre::Light::LT_POINT);
		break;

	default: // Default por si acaso.
		std::cout << "Luz default: direccional." << std::endl;
		luz->setType(Ogre::Light::LT_DIRECTIONAL);
		break;
	}

	luz->setDiffuseColour(0.75, 0.75, 0.75);
	mLightNode = sCMan->getRootSceneNode()->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0.0, -1.0, 0.0)); // Apunta hacia abajo.
	mLightNode->setPosition(getCenter().x, getCenter().y + 500, getCenter().z);
}

void Labyrinth::updateLight()
{
	if (lightMoves && hero != nullptr && mLightNode != nullptr)
		mLightNode->setPosition(hero->getPosition().x, 250, hero->getPosition().z); // Por alguna razon tiene ese offset...
}