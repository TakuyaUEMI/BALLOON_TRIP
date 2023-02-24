#include "GAME.h"
#include"libOne.h"
#include"CONTAINER.h"
#include"SCENE.h"
#include"TITLE.h"
#include"FIXED_STAGE.h"
#include"AUTO_STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
GAME::GAME() {
    Container = new CONTAINER;
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[FIXED_STAGE_ID] = new FIXED_STAGE(this);
    Scenes[AUTO_STAGE_ID] = new AUTO_STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);

    Player = new PLAYER(this);
}

GAME::~GAME() {
    delete Container;
}

void GAME::run() {
	window(1920, 1080, full);
	hideCursor();
    Container->load();
    for (int i = 0; i < NUM_SCENES; i++) {
        Scenes[i]->create();
    }
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        //Scenes[CurSceneId]->proc();
    }
}

void GAME::changeScene(SCENE_ID sceneId) {
    CurSceneId = sceneId;
}

void GAME::draw() {
    clear();
    Player->draw();
}