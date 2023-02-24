#include "GAME_OVER.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::create() {
	GameOver = game()->container()->data().gameOver;
}
void GAME_OVER::draw() {
	clear(GameOver.backColor);
}
void GAME_OVER::nextScene() {

}