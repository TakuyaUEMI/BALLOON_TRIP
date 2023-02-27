#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
class CHARACTER :
    public GAME_OBJECT
{
public:
    struct DATA {
        char characterID = 0;
        VECTOR2 posit;
        int active;
        float collisionRadius;
    };
protected:
    DATA Character;
public:
    CHARACTER(class GAME* game);
    ~CHARACTER();
    virtual void create();
    virtual void init();
    virtual void appear(float wx,float wy,VECTOR2 vec);
    virtual void update();
    virtual void draw();
    //getter
    VECTOR2 posit() { return Character.posit; }
    float collisionRadius() { return Character.collisionRadius; }
    char characterID() { return Character.characterID; }
    virtual int active() { return Character.active; }
};

