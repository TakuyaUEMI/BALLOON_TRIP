#include "FIXED_STAGE.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
#include"CHARACTER_MANAGER.h"
FIXED_STAGE::FIXED_STAGE(class GAME* game):
	SCENE(game){
}
FIXED_STAGE::~FIXED_STAGE() {

}
void FIXED_STAGE::init() {
	game()->map()->init();
	game()->characterManager()->init();
}
void FIXED_STAGE::update() {
	game()->characterManager()->update();
	game()->map()->update();
}
void FIXED_STAGE::draw() {
	clear(128);
	game()->map()->draw();
	game()->characterManager()->draw();
}
void FIXED_STAGE::nextScene() {

}