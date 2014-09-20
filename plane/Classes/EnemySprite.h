#ifndef ENEMYSPRITE_H
#define ENEMYSPRITE_H


#include "cocos2d.h"
#include "EnemyInfo.h"

USING_NS_CC;

class EnemySprite : public Node
{
public:
    EnemySprite();
    ~EnemySprite();
    virtual bool init();
    CREATE_FUNC(EnemySprite);
public:
    void setEnemyByType(EnemyType enType);
    Sprite* getSprite();
    int getLife();
    void loseLife();
    Rect getBoundingBox();
    Point getcurPoint();

private:
    Sprite* pEnemySprite;
    int nLife;
};

#endif // ENEMYSPRITE_H
