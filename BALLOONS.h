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
    void create() override;
    void init() override;
    void appear(float wx, float wy,VECTOR2 vec) override;
    void update() override;
    void move();
    void collision();
    void miss();
    void draw() override;
    void kill(int i);
    int consecutiveNum() { return AllBalloon.consecutiveNum; }
    void setColor(COLOR c) { AllBalloon.fillColor = c; }

};

