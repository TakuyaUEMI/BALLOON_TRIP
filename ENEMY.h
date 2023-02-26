#pragma once
#include "CHARACTER.h"
#include"VECTOR2.h"
#include"COLOR.h"
class ENEMY :
    public CHARACTER
{
public:
    struct DATA {
        //ˆÚ“®ŠÖŒW
        VECTOR2 posit;
        VECTOR2 advSpeed;
        float angleSpeed;
        //•\Ž¦—p
        COLOR fillColor;
        float wide;
        float high;
        float angle;
        //‚ ‚½‚è”»’è—p
        float collisionRadius;
    };
};

