#include "PigSprite.h"
#include "PlaneLayer.h"

PigSprite::PigSprite(){}
PigSprite::~PigSprite(){}

bool PigSprite::init()
{
    if(!Sprite::init())
    {
        return false;
    }

    Size winSize = Director::getInstance()->getWinSize();
    spritepig = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_01.png"));

    this->setPosition(Point(winSize.width/2, winSize.height/2));
    this->addChild(spritepig);

    //设置缩放为原来的0.6
    this->setScale(0.6);
    f_createAnimate(3, 8);

    //时间调度，保持每一帧小猪都在飞机周围
    this->schedule(schedule_selector(PigSprite::f_followPlane));
    return true;
}

//更新猪位置，到达边界时，更新到左边或右边
void PigSprite::f_followPlane(float dt)
{
    Size winSize = Director::getInstance()->getWinSize();
    auto PlanePos = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
    if(PlanePos.x + 60 + spritepig->getContentSize().width <= winSize.width)
    {
        this->setPosition( Point(PlanePos.x + 60 + spritepig->getContentSize().width/2, PlanePos.y) );
    }
    else
    {
        this->setPosition(Point(PlanePos.x - 60 - spritepig->getContentSize().width/2, PlanePos.y));
    }
}

void PigSprite::f_createAnimate(int count, int fps)
{
    char buff[16];
    Animation* panimation = Animation::create();
    panimation->setDelayPerUnit(1.0/ fps);
    for(int id = 1; id<=count; id++)
    {
        sprintf(buff, "hero_0%d.png", id);
        panimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
    }
    spritepig->runAction(RepeatForever::create(Animate::create(panimation)));
}
