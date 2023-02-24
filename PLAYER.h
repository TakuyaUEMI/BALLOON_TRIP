#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
#include"COLOR.h"
class PLAYER :
    public GAME_OBJECT
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

