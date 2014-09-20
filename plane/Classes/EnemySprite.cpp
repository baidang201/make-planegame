#include "EnemySprite.h"
EnemySprite::EnemySprite(){}
EnemySprite::~EnemySprite(){}

void EnemySprite::setEnemyByType(EnemyType enType)
{
    switch(enType)
    {
    case Enemy1:
        pEnemySprite = Sprite::createWithSpriteFrame( SpriteFrameCache::getInstance()->getSpriteFrameByName("n1.png") );
        nLife = ENEMY1_MAXLIFE;
        break;
    case Enemy2:
        pEnemySprite = Sprite::createWithSpriteFrame( SpriteFrameCache::getInstance()->getSpriteFrameByName("n2.png") );
        nLife = ENEMY2_MAXLIFE;
        break;
    case Enemy3:
        pEnemySprite = Sprite::createWithSpriteFrame( SpriteFrameCache::getInstance()->getSpriteFrameByName("n3.png") );
        nLife = ENEMY3_MAXLIFE;
        break;
    case Enemy4:
        pEnemySprite = Sprite::createWithSpriteFrame( SpriteFrameCache::getInstance()->getSpriteFrameByName("n_boss.png") );
        nLife = ENEMY3_MAXLIFE;
        break;

    default:
        return;
        break;
    }
    this->addChild(pEnemySprite);
    pEnemySprite->setScale(0.6f);
    Size winSize = Director::getInstance()->getWinSize();
    Size enemySize = pEnemySprite->getContentSize();

    //随机出现位置
    int minX = enemySize.width / 2;
    int maxX = winSize.width-enemySize.width/2;
    int rangeX = maxX - minX;
    int actualX = (rand() % rangeX)+minX;
    this->setPosition( Point(actualX, winSize.height +enemySize.height / 2));
}

bool EnemySprite::init()
{
    bool pRet = true;
    if(!Node::init())
    {
        pRet = false;
    }
    return pRet;
}

Sprite* EnemySprite::getSprite()
{
    return pEnemySprite;
}

int EnemySprite::getLife()
{
    return nLife;
}

void EnemySprite::loseLife()
{
    nLife=nLife - 0.5;
}

Point EnemySprite::getcurPoint()
{
	return this->getPosition();
}
Rect EnemySprite::getBoundingBox()
{
    Rect rect = pEnemySprite->boundingBox();
    Point pos = this->convertToWorldSpace(rect.origin);
    Rect enemyRect(pos.x, pos.y, rect.size.width, rect.size.height);
    return enemyRect;
}
