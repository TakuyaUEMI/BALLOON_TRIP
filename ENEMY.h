#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class ENEMY :
    public CHARACTER
{
public:
    struct DATA {
        //�ړ��֌W
        VECTOR2 posit;
        VECTOR2 advSpeed;
        float angleSpeed;
        //�\���p
        COLOR fillColor;
        float wide;
        float high;
        float angle;
        //�����蔻��p
        float collisionRadius;
    };
private:
    DATA Enemy;
public:
    ENEMY(class GAME* game);
    ~ENEMY();
    void create() override;
    void init() override;
    void appear(float wx, float wy,VECTOR2 vec) override;
    void update() override;
    void move();
    void draw() override;
    //getter
    VECTOR2 posit() { return Enemy.posit; }
    float collosionRadius() { return Enemy.collisionRadius; }
    int active() override{ return Character.active; }
};


