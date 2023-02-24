#include "FIXED_STAGE.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
FIXED_STAGE::FIXED_STAGE(class GAME* game):
	SCENE(game){
}
FIXED_STAGE::~FIXED_STAGE() {

}
void FIXED_STAGE::init() {

}
void FIXED_STAGE::update() {
	
}
void FIXED_STAGE::draw() {
	clear();
	game()->draw();
}
void FIXED_STAGE::nextScene() {

}