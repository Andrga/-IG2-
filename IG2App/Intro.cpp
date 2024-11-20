#include "Intro.h"

Intro::Intro(SceneManager* SM, SceneNode* sNode)
	: sMang(SM), introNode(sNode)
{

	setUpScene();

}

Intro::~Intro()
{



}

void Intro::setUpScene()
{
	// Una luz para guiarnos en la oscuridad,
	Light* luz = sMang->createLight("LuzIntro");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);
	mLightNode = sMang->getRootSceneNode()->createChildSceneNode("nLuzIntro");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0.0, -1.0, 0.0)); // Apunta hacia abajo.

	// Un suelo que pisar,
	createGround();

	// Un hero para salvarnos,
	hero = new HeroIntro({ 0, 0, 0 }, introNode, sMang);
	hero->setScale({ 20, 20, 20 });

	// Una cabeza para pensar pensamientos,
	//head = new OgreHeadIntro({ 100, 0, 0 }, introNode, sMang);
	//head->setScale({ 5, 5, 5 });

	animationStateDance = hero->addTrack(sMang);

	// Y una animacion para alegrarnos el dia.
	/*animationStateDance = hero->getAnim("sinbadWalking");
	animationStateDance->setLoop(true);
	animationStateDance->setEnabled(true);*/
}


void Intro::setVisible(bool vis)
{
	introNode->setVisible(vis);
}

void Intro::update(const Ogre::FrameEvent& evt)
{
	if (animationStateDance != nullptr)
	{
		animationStateDance->addTime(evt.timeSinceLastFrame);
	}
}

void Intro::createGround()
{
	Plane ground(Vector3::UNIT_Y, 0); // Plano con orientacion.

	Ogre::MeshManager::getSingleton().createPlane(
		"groundIntro", // Nombre de la nueva mesh.
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, // Grupo.
		ground, // Plano base.
		1000, 1000, // Tamanyo.
		20, 20, // Segmentos.
		true, 1, // Normales y numTexCoordSet.
		5, 5, // repeticiones de la textura.
		Vector3::UNIT_Z); // Orientacion.


	Entity* eGround = sMang->createEntity("sueloIntro", "groundIntro");
	nGround = sMang->getRootSceneNode()->createChildSceneNode("groundNodeIntro");
	nGround->attachObject(eGround);

	nGround->setPosition({ 0, 0, 0 });
	//eGround->setMaterialName("matFloor"); // Material del suelo.
}

void Intro::trackMovimiento()
{



}
