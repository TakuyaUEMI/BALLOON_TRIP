#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
#include"COLOR.h"
class PLAYER :
    public GAME_OBJECT
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
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void init();
    void update();
        void move();
    void draw();
};

