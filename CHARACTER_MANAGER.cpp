#include "CHARACTER_MANAGER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"BALLOONS.h"
#include"ENEMY.h"
#include"libOne.h"
#include"CONTAINER.h"
#include"CHARACTER.h"

CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game):
	GAME_OBJECT(game){
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
	delete[] Chara;
	delete Player;
	delete Balloons;
}
void CHARACTER_MANAGER::create() {
	CM = game()->container()->data().charaManager;
	CM.total = CM.numPlayer + CM.numBalloon + CM.numEnemies;
	Player = new PLAYER(game());
	Balloons = new BALLOONS(game());
	Chara = new CHARACTER*[CM.total];
	int i = 0, j = 0;
	//Chara[0] = new PLAYER(game());
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
void CHARACTER_MANAGER::appear(char ID, float wx, float wy, VECTOR2 vec)
{
	for (int i = 0; i < CM.total; i++) {
		if (Chara[i]->characterID() == ID) {
			if (Chara[i]->active() == 0) {
				Chara[i]->appear(wx, wy, vec);
				break;
			}
		}
	}
}

void CHARACTER_MANAGER::update() {
	for (int i = 0; i < CM.total; i++) {
		Chara[i]->update();
	}
	collision();
	//Chara[0]->update();
}
void CHARACTER_MANAGER::collision() {
	for (int i = CM.numPlayer + CM.numBalloon; i < CM.total; i++) {
		if (Chara[i]->active() == 1) {
			float dist = Player->collisionRadius() + Chara[i]->collisionRadius();
			float sqDist = dist * dist;
			VECTOR2 vec = Player->posit() - Chara[i]->posit();
			if (sqLength(vec) < sqDist) {
				Player->damage();
			}
		}
	}
}
void CHARACTER_MANAGER::draw() {
	for (int i = 0; i < CM.total; i++) {
		Chara[i]->draw();
	}
	//Chara[0]->draw();
}