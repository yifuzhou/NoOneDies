#include "GameController.h"

bool GameController::_isUp = true;
GameController* GameController::create(cocos2d::Layer* layer, float positionY)
{
	auto  _ins = new GameController();
	_ins->init(layer, positionY);
	_ins->autorelease();
	return _ins;
	
}

bool GameController::init(cocos2d::Layer*layer, float positionY)
{
	
	_layer = layer;
	_positionY = positionY;

	visibleSize = Director::getInstance()->getVisibleSize();

	//add ground
	ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	ground->setPosition(visibleSize.width / 2, positionY);
	ground->setPhysicsBody(PhysicsBody::createBox(ground->getContentSize()));
	ground->getPhysicsBody()->setDynamic(false);
	ground->getPhysicsBody()->setContactTestBitmask(1);
	ground->setTag(1);
	layer->addChild(ground);

	//add Edge
	edge = Edge::create();
	edge->setContentSize(visibleSize);
	layer->addChild(edge);
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
	

	//add hero
	s = Sprite::create("bird_blue_0.png");
	s->setPhysicsBody(PhysicsBody::createBox(s->getContentSize()));
	s->setPosition(50, s->getContentSize().height / 2 + positionY);
	s->getPhysicsBody()->setContactTestBitmask(1);
	s->setTag(2);
	layer->addChild(s);

	resetFrames();
	

	return true;
}

void GameController::addBlock()
{
	auto b = Block::create();
	_layer->addChild(b);
	b->setPositionY(b->getContentSize().height / 2 + _positionY);

}

void GameController::resetFrames()
{
	currentFrameIndex = 0;
	nextFrameCout = (rand() % 120) + 100;
}

void GameController::OnUpdate(float dt)
{
	currentFrameIndex++;
	if (currentFrameIndex >= nextFrameCout)
	{
		resetFrames();
		addBlock();
	}
}

bool GameController::hitTestPoint(Vec2 point)
{
	Rect a;
	return (edge->getBoundingBox().containsPoint(point));
	edge->getBoundingBox() = a;
	
	
}
bool GameController::getIsUp()
{
	return _isUp;
}

void GameController::setIsUp(bool isUp)
{
	_isUp = isUp;
}

void GameController::onUserTouch()
{
	
	if (getIsUp()==true)
	{
		s->getPhysicsBody()->setVelocity(Vec2(0, 400));
		setIsUp(false);
	}
}

