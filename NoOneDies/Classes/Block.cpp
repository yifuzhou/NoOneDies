#include "Block.h"

bool Block::init()
{
	Sprite::init();

	Size s = Size((rand() % 20) + 5, (rand() % 30) + 10);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	setPhysicsBody(PhysicsBody::createBox(s));
	setTextureRect(Rect(0, 0, s.width, s.height));
	setColor(Color3B(0, 0, 0));
	setContentSize(s);

	setPositionX(visibleSize.width);
	scheduleUpdate() ;

	getPhysicsBody()->setDynamic(false);

	getPhysicsBody()->setContactTestBitmask(1);
	setTag(3);
	return true;
	
}

void Block::update(float dt)
{
	this->setPositionX(getPositionX() - 3);
	if (getPositionX() < 0)
	{
		unscheduleUpdate();
		removeFromParent();
	}

}