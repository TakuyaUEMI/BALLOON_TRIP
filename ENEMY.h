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
};
