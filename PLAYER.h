#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
#include"COLOR.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        //�摜�ԍ�
        int img;
        //�ړ��֌W
        VECTOR2 posit;
        VECTOR2 advSpeed;
        VECTOR2 accel;
        VECTOR2 maxSpeed;
        VECTOR2 reductionRate;
        float gravity;
        //�̗͊֌W
        int hp;
        int initHp;
        float invicibleTime;
        float invicibleRestTime;
        //������
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

