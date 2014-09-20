#ifndef PLANELAYER_H
#define PLANELAYER_H
#include "cocos2d.h"
#include "PigSprite.h"
USING_NS_CC;
enum Enum_Plane
{
    AIRPLANE = 1,
};

class PlaneLayer:public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    void menuCloseCallback(Ref* pSender);
    static PlaneLayer* create();
public:
    PigSprite* mp_pig;
    static PlaneLayer* sharedPlane;
    void f_createSprite();
public:
    bool onTouchBegan(Touch* touch, Event* pEvent);
    void onTouchMoved(Touch* touch, Event* pEvent);
};

#endif // PLANELAYER_H
