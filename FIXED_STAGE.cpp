#include "FIXED_STAGE.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
#include"CHARACTER_MANAGER.h"
#include"SCORE.h"
FIXED_STAGE::FIXED_STAGE(class GAME* game):
	SCENE(game){
}
FIXED_STAGE::~FIXED_STAGE() {
}
void FIXED_STAGE::create() {
	Fs = game()->container()->data().fs;
}
void FIXED_STAGE::init() {
	game()->map()->init();
	game()->characterManager()->init();
	game()->score()->init();
}
void FIXED_STAGE::update() {
	game()->map()->update();
	game()->characterManager()->update();
	game()->score()->update();
}
void FIXED_STAGE::draw() {
	clear(Fs.backColor);
	game()->map()->draw();
	game()->characterManager()->draw();
	game()->score()->draw();
}
void FIXED_STAGE::nextScene() {
	if (game()->characterManager()->player()->hp() <= 0) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}