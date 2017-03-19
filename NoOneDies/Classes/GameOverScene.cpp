#include"GameOverScene.h"

Scene* GameOver::createScene()
{
	auto s = Scene::create();
	auto l = GameOver::create();
	s->addChild(l);
	return s;

}

bool GameOver::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto label = Label::create();
	label->setString("GAME OVER");
	label->setSystemFontSize(40);
	label->setColor(Color3B::BLACK);
	addChild(label);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	auto restartLabel = Label::create();
	restartLabel->setString("AGAIN");
	restartLabel->setSystemFontSize(20);
	restartLabel->setColor(Color3B::RED);
	addChild(restartLabel);
	restartLabel->setPosition(visibleSize.width / 2-100, visibleSize.height / 2 - 100);

	auto listen = EventListenerTouchOneByOne::create();
	listen->onTouchBegan = [restartLabel, this](Touch* t, Event* e)
	{
		if (restartLabel->getBoundingBox().containsPoint(t->getLocation()))
			Director::getInstance()->replaceScene(TransitionFadeBL::create(1, HelloWorld::createScene()));
		return false;
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listen, restartLabel);

	auto endLabel = Label::create();
	endLabel->setString("END");
	endLabel->setSystemFontSize(20);
	endLabel->setColor(Color3B::RED);
	addChild(endLabel);
	endLabel->setPosition(visibleSize.width / 2+100, visibleSize.height / 2 - 100);

	auto endlisten = EventListenerTouchOneByOne::create();
	endlisten->onTouchBegan = [endLabel, this](Touch* t, Event* e)
	{
		if (endLabel->getBoundingBox().containsPoint(t->getLocation()))
			Director::getInstance()->end();
		return false;
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(endlisten, endLabel);


	return true;
}

 