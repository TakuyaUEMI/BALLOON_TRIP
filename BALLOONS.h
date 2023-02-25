#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class BALLOONS :
    public CHARACTER
{
public:
    struct DATA {
        //画像番号
        int img;
        //風船の数
        int totalNum;
        int currentNum;
        int consecutiveNum;
        //体力関係
        int initHp;
        //見た目
        COLOR fillColor;
        float diameter;
        //フラグ
        int missFrag;
        //あたり判定用
        float collisionRadius;
    };
private:
    DATA AllBalloon;
    struct BALLOON {
        VECTOR2 posit;
        VECTOR2 advSpeed;
        int hp;
    };
    BALLOON* Balloon;
public:
    BALLOONS(class GAME* game);
    ~BALLOONS();
    void create();
    void init();
    void appear(float wx, float wy);
    void update();
    void move();
    void draw();
    void kill();
};

