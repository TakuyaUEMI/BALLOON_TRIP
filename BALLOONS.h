#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class BALLOONS :
    public CHARACTER
{
public:
    struct DATA {
        //�摜�ԍ�
        int img;
        //���D�̐�
        int totalNum;
        int currentNum;
        int consecutiveNum;
        //�̗͊֌W
        int initHp;
        //������
        COLOR fillColor;
        float diameter;
        //�t���O
        int missFrag;
        //�����蔻��p
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

