#include "Intro.h"

Intro::Intro(SceneManager* SM, SceneNode* sNode)
	:sMang(SM), introNode(sNode)
{

	setUpScene();

}

Intro::~Intro()
{



}

void Intro::setUpScene()
{

}


void Intro::setVisible(bool vis)
{
	introNode->setVisible(vis);
}
