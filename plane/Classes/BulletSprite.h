#ifndef BULLETSPRITE_H
#define BULLETSPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class BulletSprite: public Layer
{
public:
    BulletSprite();
    ~BulletSprite();
    virtual bool init();
    CREATE_FUNC(BulletSprite);

    Animation* f_createAnimate(int count, int fps);//创建子弹运行的动画
    void removeBullet(Node* pNode);//移除超出屏幕，或碰撞后的子弹
    void ShootBullet(float dt);//发射子弹，在其中进行子弹的渲染和子弹的飞行动作
public:
    Vector <Sprite*>vecBullet;
    SpriteBatchNode* bulletBatchNode;
};

#endif // BULLETSPRITE_H
