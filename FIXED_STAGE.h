#pragma once
#include "SCENE.h"
class FIXED_STAGE :
    public SCENE
{
public:
    FIXED_STAGE(class GAME* game);
    ~FIXED_STAGE();
    void init();
    void update();
    void draw();
    void nextScene();
};

