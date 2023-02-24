#pragma once
#include "SCENE.h"
#include"VECTOR2.h"
#include"COLOR.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        //�w�i
        COLOR backColor;
        //�N���A�e�L�X�g
        COLOR clearTextColor;
        float clearTextSize;
        VECTOR2 clearTextPosit;
        char clearTextStr[20];
        //�^�C�g���ɖ߂���@�e�L�X�g
        COLOR finishTextColor;
        float finishTextSize;
        VECTOR2 finishTextPosit;
        char finishStr[100];
    };
private:
    DATA GameClear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void draw();
    void nextScene();
};

