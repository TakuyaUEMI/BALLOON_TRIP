#include "GAME.h"
#include"libOne.h"
#include"CONTAINER.h"
#include"SCENE.h"
#include"TITLE.h"
#include"FIXED_STAGE.h"
#include"AUTO_STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CHARACTER_MANAGER.h"
#include"MAP.h"
GAME::GAME() {
    Container = new CONTAINER;
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[FIXED_STAGE_ID] = new FIXED_STAGE(this);
    Map = new MAP(this);
    Scenes[AUTO_STAGE_ID] = new AUTO_STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);

    CharacterManager = new CHARACTER_MANAGER(this);
    Score = new SCORE(this);

}

GAME::~GAME() {
    delete Score;
    delete CharacterManager;
    delete Map;
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
    delete Container;
}

//ゲームの実行
void GAME::run() {
	window(1920, 1080,full);
	hideCursor();
    Container->load();
    for (int i = 0; i < NUM_SCENES; i++) {
        Scenes[i]->create();
    }
    CharacterManager->create();
    Map->create();
    Score->create();
    CurSceneId = TITLE_ID;
    Scenes[CurSceneId]->init();
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
    }
}

void GAME::changeScene(SCENE_ID sceneId) {
    CurSceneId = sceneId;
    Scenes[CurSceneId]->init();
}