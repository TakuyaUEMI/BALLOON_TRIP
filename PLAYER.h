#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        //‰æ‘œ”Ô†
        int img;
        //ˆÚ“®ŠÖŒW
        VECTOR2 posit;
        VECTOR2 advSpeed;
        VECTOR2 accel;
        VECTOR2 maxSpeed;
        VECTOR2 reductionRate;
        float reductionRatio;
        float gravity;
        //‘Ì—ÍŠÖŒW
        int hp;
        int initHp;
        float invicibleTime;
        float invicibleRestTime;
        //Œ©‚½–Ú
        COLOR fillColor;
        float wide;
        float high;
        //‚ ‚½‚è”»’è—p
        float collisionRadius;
    };
private:
    DATA Player;
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
    //VECTOR2 posit() { return Character.posit; }
    int hp() { return Player.hp; }
    //float collisionRadius() { return Character.collisionRadius; };
};

