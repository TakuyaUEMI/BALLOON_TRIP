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
	setFixedStage();
	setGameOver();
	setMap();
	setPlayer();
	setBalloons();
	setScore();
	setEnemy();
	setCharaManager();
}

void CONTAINER::setTitle() {
	D.title.backColor = COLOR(50);

	D.title.titleTextColor = COLOR(235, 10, 100);
	D.title.titleTextSize = 300;
	D.title.titlePosit = VECTOR2(50, 400);
	strcpy_s(D.title.titleStr, "BALLOON TRIP");

	D.title.manualTextColor = COLOR(255, 255, 255);
	D.title.manualTextSize = 120;
	D.title.manualPosit = VECTOR2(350, 600);
	strcpy_s(D.title.manualStr, "Left:A  Right:D  Up:K");

	D.title.startTextColor = COLOR(255, 255, 255);
	D.title.startTextSize = 150;
	D.title.startPosit = VECTOR2(500, 800);
	strcpy_s(D.title.startStr, "PRESS SPACE");
}
void CONTAINER::setFixedStage() {
	D.fs.backColor = COLOR(50);
}
void CONTAINER::setMap() {
	D.map.fileName = "stage.txt";
	D.map.chipSize = 60;
	D.map.scrollSpeed = 120;

	D.map.randBalloon = 16;//0Å`19Ç≈í≤êÆÅAëÂÇ´Ç¢Ç∆ämó¶Ç™â∫Ç™ÇÈ
	D.map.randEnemy = 4;
	D.map.maxEnemySpeedX = 40;
	D.map.maxEnemySpeedY = 80;

}
void CONTAINER::setGameClear() {

}
void CONTAINER::setGameOver() {
	D.gameOver.backColor = COLOR(50);
	D.gameOver.overTextColor = COLOR(225,50,200);
	D.gameOver.overTextSize = 300;
	D.gameOver.overTextPosit = VECTOR2(100, 500);
	strcpy_s(D.gameOver.overTextStr, "GAME OVER");

	D.gameOver.continueTextColor = COLOR(240,240,10);
	D.gameOver.continueTextSize = 120;
	D.gameOver.continueTextPosit = VECTOR2(330, 700);
	strcpy_s(D.gameOver.continueStr, "CONTINUE:PRESS SPACE");
	strcpy_s(D.gameOver.continueStr2, "TITLE:PRESS ENTER");

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
	D.player.accel = VECTOR2(700, 920);
	D.player.maxSpeed = VECTOR2(550, 750);
	D.player.reductionRate = (30, 30);
	D.player.reductionRatio = 0.99f;
	D.player.gravity = 400;

	D.player.hp = 1;
	D.player.initHp = 1;
	D.player.invicibleTime = 1.0f;
	D.player.invicibleRestTime = 2.0f;

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
	D.balloons.collisionRadius = D.balloons.diameter / 2 + 10;
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
	D.enemyCharacter.collisionRadius = 20;
}

void CONTAINER::setScore(){
	D.score.currentScore = 0;
	D.score.currentIndex = 0;
	const int totalIndex = 4;
	D.score.totalIndex = totalIndex;
	int scoreList[totalIndex] = { 100,200,400,800 };
	int borderList[totalIndex] = { 0,10,20,30 };
	COLOR fillColor[totalIndex] = { COLOR(150,240,10),COLOR(240,150,10),COLOR(240,35,10),COLOR(240,20,220)};
	for (int i = 0; i < totalIndex; i++) {
		D.score.scoreList[i] = scoreList[i];
		D.score.borderList[i] = borderList[i];
		D.score.fillColor[i] = fillColor[i];
	}
	D.score.posit = VECTOR2(100, 100);
	D.score.color = COLOR(255, 255, 255);
	D.score.textSize = 100;
	strcpy_s(D.score.str, "SCORE:");
}