#pragma once
#include "SCENE.h"
#include"VECTOR2.h"
#include"COLOR.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        //�w�i
        COLOR backColor;
        //�Q�[���I�[�o�[�e�L�X�g
        COLOR overTextColor;
        float overTextSize;
        VECTOR2 overTextPosit;
        char overTextStr[20];
        //�Q�[���R���e�B�j���[���@�e�L�X�g
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

