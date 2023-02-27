#include "BALLOONS.h"
#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include"SCORE.h"

BALLOONS::BALLOONS(class GAME* game):
	CHARACTER(game){
}
BALLOONS::~BALLOONS() {

}
void BALLOONS::create() {
	AllBalloon = game()->container()->data().balloons;
	Character = game()->container()->data().balloonsCharacter;
	Balloon = new BALLOON[AllBalloon.totalNum];
}
void BALLOONS::init() {
	AllBalloon.currentNum = 0;
	AllBalloon.consecutiveNum = 0;

}
void BALLOONS::appear(float wx, float wy,VECTOR2 vec) {
	Balloon[AllBalloon.currentNum].posit.x = wx + AllBalloon.diameter / 2;
	Balloon[AllBalloon.currentNum].posit.y = wy + AllBalloon.diameter / 2;
	AllBalloon.currentNum++;
	
}
void BALLOONS::update() {
	move();
	collision();
	miss();
	
}
void BALLOONS::move() {
	for (int i = AllBalloon.currentNum - 1; i >= 0; i--) {
		Balloon[i].posit.x -= game()->map()->scrollSpeed()*delta;
	}
}
void BALLOONS::draw() {
	fill(AllBalloon.fillColor);
	for (int i = AllBalloon.currentNum - 1; i >= 0; i--) {
		circle(Balloon[i].posit.x, Balloon[i].posit.y, AllBalloon.diameter);
	}
}
void BALLOONS::collision() {
	PLAYER* player = game()->characterManager()->player();
	float distance = player->collisionRadius() + AllBalloon.collisionRadius;
	float sqDistance = distance * distance;
	for (int i = AllBalloon.currentNum - 1; i >= 0; i--) {
		VECTOR2 vec = player->posit() - Balloon[i].posit;
		if (sqLength(vec) < sqDistance) {
			kill(i);
			AllBalloon.consecutiveNum++;
			game()->score()->addScore();
		}
	}
}
void BALLOONS::miss() {
	for (int i = AllBalloon.currentNum - 1; i >= 0; i--) {
		if (Balloon[i].posit.x < -AllBalloon.diameter / 2) {
			kill(i);
			AllBalloon.consecutiveNum = 0;
		}
	}
}

void BALLOONS::kill(int i) {
	AllBalloon.currentNum--;
	Balloon[i] = Balloon[AllBalloon.currentNum];
}