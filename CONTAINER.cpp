#include "CONTAINER.h"
#include"libOne.h"
CONTAINER::CONTAINER() {

}

CONTAINER::~CONTAINER() {

}

void CONTAINER::load() {
	setData();
	loadGraphic();
}

void CONTAINER::setData() {
	setTitle();
	setMap();
	setPlayer();
	setBalloons();
}

void CONTAINER::setTitle() {
	D.title.backColor = COLOR(50,50,50);

	D.title.titleTextColor = COLOR(235, 10, 100);
	D.title.titleTextSize = 80;
	D.title.titlePosit = VECTOR2(100, 400);
	strcpy_s(D.title.titleStr, "BALLOON TRIP");

	D.title.manualTextColor = COLOR(255, 255, 255);
	D.title.manualTextSize = 50;
	D.title.manualPosit = VECTOR2(200, 600);
	strcpy_s(D.title.manualStr, "Left:A  Right:D  Up:K");

	D.title.startTextColor = COLOR(255, 255, 255);
	D.title.startTextSize = 60;
	D.title.startPosit = VECTOR2(200, 800);
	strcpy_s(D.title.startStr, "PRESS ENTER");
}
void CONTAINER::setMap() {
	D.map.fileName = "stage.txt";
	D.map.chipSize = 60;
	D.map.scrollSpeed = 60;
}
void CONTAINER::setGameClear() {

}
void CONTAINER::setGameOver() {

}

void CONTAINER::loadGraphic() {

}
void CONTAINER::setPlayer() {
	D.playerCharacter.characterID = MAP::PLAYER_ID;

	D.player.posit = VECTOR2(120, height);
	D.player.advSpeed = VECTOR2(0, 0);
	D.player.accel = VECTOR2(10, 20);
	D.player.maxSpeed = VECTOR2(10, 10);
	D.player.reductionRate = (30, 30);
	D.player.reductionRatio = 0.99f;
	D.player.gravity = 6.0f;

	D.player.hp = 5;
	D.player.initHp = 5;
	D.player.invicibleTime = 1.0f;
	D.player.invicibleRestTime = 0;

	D.player.fillColor = COLOR(100, 220, 230);
	D.player.wide = 60;
	D.player.high = 60;
}

void CONTAINER::setBalloons() {
	D.balloonsCharacter.characterID = MAP::BALLOON_ID;

	D.balloons.totalNum = 100;
	D.balloons.currentNum = 0;
	D.balloons.consecutiveNum = 0;
	D.balloons.initHp = 1;
	D.balloons.fillColor = COLOR(150, 240, 10);
	D.balloons.diameter = 60;
	D.balloons.missFrag = 0;
	D.balloons.collisionRadius = D.balloons.diameter / 2;
}