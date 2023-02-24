#pragma once
#include "SCENE.h"
#include"VECTOR2.h"
#include"COLOR.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        //背景
        COLOR backColor;
        //ゲームオーバーテキスト
        COLOR overTextColor;
        float overTextSize;
        VECTOR2 overTextPosit;
        char overTextStr[20];
        //ゲームコンティニュー方法テキスト
        COLOR continueTextColor;
        float continueTextSize;
        VECTOR2 continueTextPosit;
        char continueStr[100];
    };
private:
    DATA GameOver;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void draw();
    void nextScene();
};

