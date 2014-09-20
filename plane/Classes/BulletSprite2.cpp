#include "BulletSprite.h"
#include "PlaneLayer.h"

BulletSprite::BulletSprite(){}
BulletSprite::~BulletSprite(){}

bool BulletSprite::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        Texture2D* texture = TextureCache::sharedTextureCache()->textureForKey("bullet.png");
        bulletBatchNode = SpriteBatchNode::createWithTexture(texture);
        this->addChild(bulletBatchNode);

        //每隔x秒，调用一次发射子弹函数
        this->schedule(schedule_selector(BulletSprite::ShootBullet), 0.05f);
        bRet = true;
    }while(0);
    return bRet;
}

void BulletSprite::ShootBullet(float dt)
{
    Size winSize = Director::getInstance()->getWinSize();
    auto PlanePos = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();

    auto spritebullet = Sprite::createWithSpriteFrameName("bullet_1.png");
    bulletBatchNode->addChild(spritebullet);
    vecBullet.pushBack(spritebullet);
    Point bulletPos = (Point(PlanePos.x, PlanePos.y+PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height/2 + 20) );
    spritebullet->setPosition(bulletPos);
    spritebullet->setScale(0.4f);


    float flyLen = winSize.height - PlanePos.y;
    float flyVelocity = 320/1; //速冻，每秒走的像素
    float realFlyDuration = flyLen/flyVelocity;//实际飞行的时间

    auto actionMove = MoveTo::create(realFlyDuration, Point(bulletPos.x, winSize.height));
    auto actionDone =CallFuncN::create(CC_CALLBACK_1(BulletSprite::removeBullet, this) );

    Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
    spritebullet->runAction(sequence);
}

void BulletSprite::removeBullet(Node *pNode)
{
    if(NULL == pNode)
    {
        return;
    }

    Sprite* bullet = (Sprite*) pNode;
    this->bulletBatchNode->removeChild(bullet, true);
    vecBullet.eraseObject(bullet);
}

Animation* BulletSprite::f_createAnimate(int count, int fps)
{
    char buff[16];
    Animation* panimation = Animation::create();
    panimation->setDelayPerUnit(1.0 / fps);
    for(int id =1; id<=count; id++)
    {
        sprintf(buff, "bullet_%d.png", id);
        panimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));

    }
    return panimation;
}
