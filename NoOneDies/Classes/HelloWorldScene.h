#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"GameController.h"

class HelloWorld : public cocos2d::LayerColor
{
private:
	cocos2d::Vector<GameController*> gcs;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void update(float dt);

	void addBlock(float dt);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
