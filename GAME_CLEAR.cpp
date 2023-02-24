#include "GAME_CLEAR.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game):
	SCENE(game){
}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::create() {
	GameClear = game()->container()->data().gameClear;
}
void GAME_CLEAR::draw() {
	clear(GameClear.backColor);
}
void GAME_CLEAR::nextScene() {

}