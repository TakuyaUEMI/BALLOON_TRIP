#include "GAME.h"
#include"libOne.h"
#include"CONTAINER.h"
#include"SCENE.h"
GAME::GAME() {
    Container = new CONTAINER;
}

GAME::~GAME() {
    delete Container;
}

void GAME::run() {
	window(1920, 1080, full);
	hideCursor();
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        //Scenes[CurSceneId]->proc();
    }
}

void GAME::changeScene(SCENE_ID sceneId) {

}

void GAME::draw() {

}