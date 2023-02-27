#include "SCORE.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER_MANAGER.h"
#include"libOne.h"
SCORE::SCORE(class GAME* game) :
	GAME_OBJECT(game){
}
SCORE::~SCORE() {

}
void SCORE::create() {
	Score = game()->container()->data().score;
}
void SCORE::init() {
	Score.currentScore = 0;
	Score.currentIndex = 0;
}
void SCORE::update() {
	changeAddScore();
}
void SCORE::addScore() {
	Score.currentScore += Score.scoreList[Score.currentIndex];
}
void SCORE::changeAddScore() {
	for (int i = 0; i < Score.totalIndex; i++) {
		if (game()->characterManager()->balloons()->consecutiveNum() >= Score.borderList[i]){
			Score.currentIndex = i;
			game()->characterManager()->balloons()->setColor(Score.fillColor[i]);
		}
	}
}
void SCORE::draw() {
	fill(Score.color);
	textSize(Score.textSize);
	text(Score.str + (let)Score.currentScore, Score.posit.x, Score.posit.y);

}