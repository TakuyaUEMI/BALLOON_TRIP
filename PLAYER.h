#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        //画像番号
        int img;
        //移動関係
        VECTOR2 posit;
        VECTOR2 advSpeed;
        VECTOR2 accel;
        float triggerAccelY;
        VECTOR2 maxSpeed;
        float reductionRatio;
        float gravity;
        //体力関係
        int hp;
        int initHp;
        float invicibleTime;
        float invicibleRestTime;
        //見た目
        COLOR fillColor;
        float wide;
        float high;
        //あたり判定用
        float collisionRadius;
    };
private:
    DATA Player;
    int flyFrag = 0;
public:
    PLAYER(class GAME* game) :CHARACTER(game){}
    ~PLAYER();
    void create() override;
    void init() override;
    void appear(float wx,float wy,VECTOR2 vec) override;
    void update() override;
        void move();
    void draw() override;
    void damage();
    //getter
    int hp() { return Player.hp; }
};

