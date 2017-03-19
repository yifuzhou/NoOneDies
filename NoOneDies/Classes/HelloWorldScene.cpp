#include "HelloWorldScene.h"
#include"GameOverScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	gcs.insert(0, (GameController::create(this, 30)));
	//gcs.insert(0, (GameController::create(this, 300)));
	//gcs.pushBack(GameController::create(this, 330));

	//gcs.pushBack(GameController::create(this, 120));
	scheduleUpdate();


	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact &contact)
	{
		Sprite* spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
		Sprite* spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
		int tagA = spriteA->getTag();
		int tagB = spriteB->getTag();

		if (tagA == 2 && tagB == 3 || tagA == 3 && tagB == 2)
		{
			this->unscheduleUpdate();
			 Director::getInstance()->replaceScene(GameOver::createScene());
		}
		if (tagA == 1 && tagB == 2 || tagA == 2 && tagB == 1)
		{
			
		  GameController::setIsUp(true);
		}
		return true;
	};
	

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch* t, Event* e)
	{
		
		for (auto it = gcs.begin(); it != gcs.end(); it++)
		{
			if ((*it)->hitTestPoint(t->getLocation()))//在所在的区域内点击
			{
				(*it)->onUserTouch();
				break;
			}
			
		}
		return true;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority
		(touchListener, this);

	return true;
}



void HelloWorld::update(float dt)
{
	for (auto it = gcs.begin(); it != gcs.end(); it++)
	{
		(*it)->OnUpdate(dt);
	}
}
