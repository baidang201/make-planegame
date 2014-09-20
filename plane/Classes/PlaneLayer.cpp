
#include "PlaneLayer.h"
#include "BulletSprite.h"

USING_NS_CC;

PlaneLayer* PlaneLayer::sharedPlane = NULL;

Scene* PlaneLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = PlaneLayer::create();
    scene->addChild(layer);
    return scene;
}

PlaneLayer* PlaneLayer::create()
{
    PlaneLayer* pRet = new PlaneLayer();
    if(pRet && pRet->init())
    {
        pRet->autorelease();
        sharedPlane = pRet;
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool PlaneLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("pig.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wsparticle_p01.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("nplane.plist");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(PlaneLayer::menuCloseCallback, this) );
    closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2,
                                 origin.y + closeItem->getContentSize().height /2 ));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    f_createSprite();
    return true;
}

void PlaneLayer::f_createSprite()
{
    Size winSize = Director::getInstance()->getWinSize();

    auto plane = Sprite::create("mplane.png");
    plane->setTag(AIRPLANE);
    plane->setScale(0.7f);
    plane->setPosition(Point(winSize.width/2 - plane->getContentSize().width/2, winSize.height/7));
    this->addChild(plane);

    mp_pig = PigSprite::create();
    this->addChild(mp_pig);


    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);//不向下传递触摸事件
    touchListener->onTouchBegan = CC_CALLBACK_2(PlaneLayer::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(PlaneLayer::onTouchMoved, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, plane);
}

void PlaneLayer::onTouchMoved(Touch *touch, Event *pEvent)
{
    auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
    target->setPosition(touch->getLocation());

}

bool PlaneLayer::onTouchBegan(Touch *touch, Event *pEvent)
{
    auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
    Point locationInNode = target->convertToNodeSpace(touch->getLocation());
    target->setPosition(touch->getLocation());
    return true;
}

void PlaneLayer::menuCloseCallback(Ref *pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8 ) ||  (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT )
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
