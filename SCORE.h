#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
#include"COLOR.h"
class SCORE :
    public GAME_OBJECT
{
public:
    struct DATA {
        int currentScore;
        int highScore;
        int currentIndex;
        int totalIndex;
        int scoreList[10];
        int borderList[10];
        VECTOR2 posit;
        COLOR color;
        COLOR fillColor[10];
        float textSize;
        char str[20];
        char strhi[20];
    };
private:
    DATA Score;
public:
    SCORE(class GAME* game);
    ~SCORE();
    void create();
    void init();
    void update();
    void addScore();
    void changeAddScore();
    void updateHighScore();
    void draw();
};

