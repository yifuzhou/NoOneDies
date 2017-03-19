#include "hero.h"

bool hero::init()
{
	Sprite::init();
	auto s = Sprite::create("bird_blue_0.png");
	s->setPhysicsBody(PhysicsBody::createBox(s->getContentSize()));
	return true;
	
}