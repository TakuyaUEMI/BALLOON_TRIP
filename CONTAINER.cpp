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
	setScore();
	setEnemy();
	setCharaManager();
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
void CONTAINER::setCharaManager() {
	D.charaManager.numEnemies = 100;
	D.charaManager.numPlayer = 1;
	D.charaManager.numBalloon = 1;
}

void CONTAINER::loadGraphic() {

}
void CONTAINER::setPlayer() {
	D.playerCharacter.characterID = MAP::PLAYER_ID;
	D.playerCharacter.active = 0;
	D.player.posit = VECTOR2(120, height);
	D.player.advSpeed = VECTOR2(0, 0);
	D.player.accel = VECTOR2(10, 20);
	D.player.maxSpeed = VECTOR2(10, 10);
	D.player.reductionRate = (30, 30);
	D.player.reductionRatio = 0.99f;
	D.player.gravity = 6.0f;

	D.player.hp = 1;
	D.player.initHp = 1;
	D.player.invicibleTime = 1.0f;
	D.player.invicibleRestTime = 0;

	D.player.fillColor = COLOR(100, 220, 230);
	D.player.wide = 60;
	D.player.high = 60;

	D.playerCharacter.collisionRadius = 30;
}

void CONTAINER::setBalloons() {
	D.balloonsCharacter.characterID = MAP::BALLOON_ID;
	D.balloonsCharacter.active = 0;
	D.balloons.totalNum = 100;
	D.balloons.currentNum = 0;
	D.balloons.consecutiveNum = 0;
	D.balloons.initHp = 1;
	D.balloons.fillColor = COLOR(150, 240, 10);
	D.balloons.diameter = 60;
	D.balloons.missFrag = 0;
	D.balloons.collisionRadius = D.balloons.diameter / 2;
}
void CONTAINER::setEnemy() {
	D.enemyCharacter.characterID = MAP::ENEMY_ID;
	D.enemyCharacter.active = 0;
	D.enemy.posit = VECTOR2(0, 0);
	D.enemy.advSpeed = VECTOR2(0, 0);
	D.enemy.angleSpeed = 1;
	D.enemy.fillColor = COLOR(255, 255, 255);
	D.enemy.wide = 60;
	D.enemy.high = 60;
	D.enemy.angle = 45;
	D.enemyCharacter.collisionRadius = 25;
}

void CONTAINER::setScore(){
	D.score.currentScore = 0;
	D.score.currentIndex = 0;
	const int totalIndex = 4;
	D.score.totalIndex = totalIndex;
	int scoreList[totalIndex] = { 100,200,400,800 };
	int borderList[totalIndex] = { 0,10,20,30 };
	for (int i = 0; i < totalIndex; i++) {
		D.score.scoreList[i] = scoreList[i];
		D.score.borderList[i] = borderList[i];
	}
	D.score.posit = VECTOR2(100, 100);
	D.score.color = COLOR(255, 255, 255);
	D.score.textSize = 100;
	strcpy_s(D.score.str, "SCORE:");
}