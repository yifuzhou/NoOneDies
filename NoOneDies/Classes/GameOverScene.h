#include"cocos2d.h"
#include"HelloWorldScene.h"
using namespace cocos2d;

class GameOver :public LayerColor
{
public:
	virtual bool init();
	
	CREATE_FUNC(GameOver);
	static Scene* createScene();


};
