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
	setPlayer();
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
void CONTAINER::setGameClear() {

}
void CONTAINER::setGameOver() {

}

void CONTAINER::loadGraphic() {

}
void CONTAINER::setPlayer() {
	D.player.posit = VECTOR2(200, height / 2);
	D.player.advSpeed = VECTOR2(0, 0);
	D.player.accel = VECTOR2(10, 20);
	D.player.maxSpeed = VECTOR2(600, 400);
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