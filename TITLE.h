#pragma once
#include "SCENE.h"
#include"COLOR.h"
#include"VECTOR2.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        //�w�i
        COLOR backColor;
        //�^�C�g���e�L�X�g
        COLOR titleTextColor;
        float titleTextSize;
        VECTOR2 titlePosit;
        char titleStr[20];
        //��������e�L�X�g
        COLOR manualTextColor;
        float manualTextSize;
        VECTOR2 manualPosit;
        char manualStr[100];
        //�Q�[���X�^�[�g���@�e�L�X�g
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

