#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
class CHARACTER :
    public GAME_OBJECT
{
public:
    struct DATA {
        char characterID = 0;
        VECTOR2 dispPosit;
    };
protected:
    DATA Character;
public:
    CHARACTER(class GAME* game);
    ~CHARACTER();
    void create();
    void init();
    void appear();
    void update();
    void draw();
    //getter
    char characterID() { return Character.characterID; }
};

