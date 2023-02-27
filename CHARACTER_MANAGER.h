#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
class CHARACTER_MANAGER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int numPlayer = 0;
        int numBalloon = 0;
        int numEnemies = 0;
        int total = 0;
        int currentEnemyNum = 0;
    };
private:
    DATA CM;
    char c;
    char d[4];
    class PLAYER* Player = nullptr;
    class BALLOONS* Balloons = nullptr;
    class CHARACTER** Chara = nullptr;

public:
    CHARACTER_MANAGER(class GAME* game);
    ~CHARACTER_MANAGER();
    void create();
    void init();
    void appear(char ID, float wx, float wy, VECTOR2 vec);
    void update();
    void collision();
    void draw();
    PLAYER* player() { return Player; }
    BALLOONS* balloons() { return Balloons; }

};

