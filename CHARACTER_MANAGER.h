#pragma once
#include "GAME_OBJECT.h"
class CHARACTER_MANAGER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int numPlayers = 0;
        int numBalloons = 0;
        int numEnemies = 0;
    };
private:
    DATA CharacterManager;
    class PLAYER* Player = nullptr;
    class BALLOONS* Balloons = nullptr;

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

