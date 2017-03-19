#pragma once
#include"cocos2d.h"
#include"Edge.h"
#include"hero.h"

#include"Block.h"
USING_NS_CC;

class GameController :public Ref
{
private:
	Layer * _layer;
	float _positionY;
	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCout;
	Edge *edge;
	Sprite *s;
	Sprite *ground;
	void resetFrames();
	void addBlock();
	long Time;
	bool timerRunning;
	static bool _isUp;
	

public:
	virtual bool init(Layer *layer, float positionY);

	static GameController* create(Layer* layer, float positionY);

	void OnUpdate(float dt);

	static bool getIsUp();

	static void setIsUp(bool isUp);

	void onUserTouch();

	void BeginContact();

	bool hitTestPoint(Vec2 point);

}; 




