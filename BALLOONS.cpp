#include "BALLOONS.h"
#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"

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
}
void BALLOONS::appear(float wx, float wy) {
	Balloon[AllBalloon.currentNum].posit.x = wx - game()->map()->wx() + AllBalloon.diameter / 2;
	Balloon[AllBalloon.currentNum].posit.y = wy - game()->map()->wy() + AllBalloon.diameter / 2;
	AllBalloon.currentNum++;
	
}
void BALLOONS::update() {
	textSize(100);
	print(AllBalloon.currentNum);
	move();
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
void BALLOONS::kill() {

}