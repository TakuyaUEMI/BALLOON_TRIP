#include "CHARACTER_MANAGER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"BALLOONS.h"
#include"ENEMY.h"
#include"libOne.h"
#include"CONTAINER.h"
CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game):
	GAME_OBJECT(game){
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
	CM = game()->container()->data().charaManager;
}
void CHARACTER_MANAGER::create() {
	CM.total = CM.numPlayer + CM.numBalloon + CM.numEnemies;
	Player = new PLAYER(game());
	Balloons = new BALLOONS(game());
	Chara = new CHARACTER * [CM.total];
	int i = 0, j = 0;
	for (i = 0; i < CM.numPlayer; i++)	Chara[j++] = Player;
	for (i = 0; i < CM.numBalloon; i++)	Chara[j++] = Balloons;
	for (i = 0; i < CM.numEnemies; i++)	Chara[j++] = new ENEMY(game());
	
	for (int i = 0; i < CM.total; i++) {
		Chara[i]->create();
	}
}
void CHARACTER_MANAGER::init() {
	for (int i = 0; i < CM.total; i++) {
		Chara[i]->init();
	}
}
void CHARACTER_MANAGER::appear(char ID,float wx,float wy) {
	for (int i = 0; i < CM.total; i++) {
		if (Chara[i]->characterID() == ID) {
			if (1/*Œã‚Å‘‚­*/) {
				Chara[i]->appear(wx, wy);
			}
		}
	}
}
void CHARACTER_MANAGER::update() {
	for (int i = 0; i < CM.total; i++) {
		Chara[i]->update();
	}
}
void CHARACTER_MANAGER::draw() {
	for (int i = 0; i < CM.total; i++) {
		Chara[i]->draw();
	}
}