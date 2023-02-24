#pragma once
#include "SCENE.h"
class AUTO_STAGE :
    public SCENE
{
public:
    AUTO_STAGE(class GAME* game);
    ~AUTO_STAGE();
    void init();
    void update();
    void draw();
    void nextScene();
};

