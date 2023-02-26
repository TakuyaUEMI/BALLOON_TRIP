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
        VECTOR2 maxSpeed;
        VECTOR2 reductionRate;
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
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void appear(float wx,float wy);
    void update();
        void move();
    void draw();
    VECTOR2 posit() { return Player.posit; }
    float collosionRadius() { return Player.collisionRadius; }

};

