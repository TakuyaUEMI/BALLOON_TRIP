#include "CHARACTER_MANAGER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"libOne.h"
CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game):
	GAME_OBJECT(game){
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {

}
void CHARACTER_MANAGER::create() {
	Player = new PLAYER(game());
	Player->create();
}
void CHARACTER_MANAGER::init() {
	Player->create();
}
void CHARACTER_MANAGER::appear(char ID,float wx,float wy) {
	textSize(100);
	fill(255);
	print("appear");
	if (ID == Player->characterID()) {
		Player->appear(wx,wy);
		textSize(100);
		print(wx);
		print(wy);

	}
}
void CHARACTER_MANAGER::update() {
	Player->update();
}
void CHARACTER_MANAGER::draw() {
	Player->draw();
}