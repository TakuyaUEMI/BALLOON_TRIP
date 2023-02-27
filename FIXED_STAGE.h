#pragma once
#include "SCENE.h"
#include"COLOR.h"
class FIXED_STAGE :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
    };
private:
    DATA Fs;
public:
    FIXED_STAGE(class GAME* game);
    ~FIXED_STAGE();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};

