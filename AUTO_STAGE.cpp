#include "AUTO_STAGE.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
#include"CHARACTER_MANAGER.h"
#include"SCORE.h"
AUTO_STAGE::AUTO_STAGE(class GAME* game):
	SCENE(game){
}
AUTO_STAGE::~AUTO_STAGE() {

}
void AUTO_STAGE::init() {

}
void AUTO_STAGE::update(){
	game()->map()->update();
	game()->characterManager()->update();
	game()->score()->update();
}
void AUTO_STAGE::draw(){
	clear(200);
	game()->map()->draw();
	game()->characterManager()->draw();
	game()->score()->draw();
}
void AUTO_STAGE::nextScene(){

}