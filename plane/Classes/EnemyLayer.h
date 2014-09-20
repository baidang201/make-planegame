#ifndef ENEMYLAYER_H
#define ENEMYLAYER_H

#include "cocos2d.h"
#include "EnemyInfo.h"
#include "EnemySprite.h"

USING_NS_CC;

class EnemyLayer : public Layer
{
public:
    EnemyLayer();
    ~EnemyLayer();
    virtual bool init();
    CREATE_FUNC(EnemyLayer);

public:
    void addEnemy1(float dt);
        void addEnemy2(float dt);
            void addEnemy3(float dt);

            void blowupEnemy(EnemySprite* pEnemySprite); //敌人爆炸
            void removeEnemy(Node* pNode);

            void setScore(int nScore);
            int getScore();
            void updateScore(int score);

public:
            Vector<EnemySprite*> vecEnemy;
            static int m_score;
            LabelBMFont* scoreItem;

            void f_removemyAnimation(Node* pNode);
};


#endif // ENEMYLAYER_H
