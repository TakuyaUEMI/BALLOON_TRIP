#pragma once
#include "SCENE.h"
#include"COLOR.h"
#include"VECTOR2.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        //背景
        COLOR backColor;
        //タイトルテキスト
        COLOR titleTextColor;
        float titleTextSize;
        VECTOR2 titlePosit;
        char titleStr[20];
        //操作説明テキスト
        COLOR manualTextColor;
        float manualTextSize;
        VECTOR2 manualPosit;
        char manualStr[100];
        //ゲームスタート方法テキスト
        COLOR startTextColor;
        float startTextSize;
        VECTOR2 startPosit;
        char startStr[100];
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void draw();
    void nextScene();
};

