#pragma once
#include "GAME_OBJECT.h"
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
    class PLAYER* Player = nullptr;
    class BALLOONS* Balloons = nullptr;
    class ENEMY** Enemy = nullptr;
    class CHARACTER** Chara = nullptr;

public:
    CHARACTER_MANAGER(class GAME* game);
    ~CHARACTER_MANAGER();
    void create();
    void init();
    void appear(char ID, float wx, float wy);
    void update();
    void draw();
    PLAYER* player() { return Player; }
    BALLOONS* balloons() { return Balloons; }

};

