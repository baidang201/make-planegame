#ifndef PIGSPRITE_H
#define PIGSPRITE_H
#include "cocos2d.h"

USING_NS_CC;
class PigSprite: public Sprite
{
public:
    PigSprite();
    ~PigSprite();
    virtual bool init();
    CREATE_FUNC(PigSprite);

    void f_createAnimate(int count, int fps);
    void f_followPlane(float dt);
    Sprite* spritepig;
};

#endif // PIGSPRITE_H
