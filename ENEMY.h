#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class ENEMY :
    public CHARACTER
{
public:
    struct DATA {
        //移動関係
        VECTOR2 posit;
        VECTOR2 advSpeed;
        float angleSpeed;
        //表示用
        COLOR fillColor;
        float wide;
        float high;
        float angle;
        //あたり判定用
        float collisionRadius;
    };
};

