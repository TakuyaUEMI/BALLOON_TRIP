#include "CHARACTER_MANAGER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"BALLOONS.h"
#include"libOne.h"
CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game):
	GAME_OBJECT(game){
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {

}
void CHARACTER_MANAGER::create() {
	Player = new PLAYER(game());
	Balloons = new BALLOONS(game());
	Player->create();
	Balloons->create();
}
void CHARACTER_MANAGER::init() {
	Player->init();
	Balloons->init();
}
void CHARACTER_MANAGER::appear(char ID,float wx,float wy) {
	if (ID == Player->characterID()) {
		Player->appear(wx, wy);
	}
	if (ID == Balloons->characterID()) {
		Balloons->appear(wx, wy);
	}
}
void CHARACTER_MANAGER::update() {
	Player->update();
	Balloons->update();
}
void CHARACTER_MANAGER::draw() {
	Player->draw();
	Balloons->draw();
}