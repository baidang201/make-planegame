#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PlaneLayer.h"
#include "BulletSprite.h"
#include "EnemyLayer.h"

USING_NS_CC;

enum EnBackground {
	e_BackgroundA = 1,
	e_BackgroundB = 2,
};
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	virtual void onEnterTransitionDidFinish();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	
public:
	void gameUpdate(float dt);
	bool bulletCollisionEnemy(Sprite* pBullet);
	bool enemyCollisionPlane();
public:
	PlaneLayer *planeLayer;
	BulletSprite *bulletSprite;
	EnemyLayer *enemyLayer;

	int getRand(int start, int end);
};

#endif // __HELLOWORLD_SCENE_H__
