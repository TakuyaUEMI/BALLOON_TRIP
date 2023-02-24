#include "PLAYER.h"
#include"libOne.h"
PLAYER::PLAYER(class GAME* game):
	GAME_OBJECT(game){
}
PLAYER::~PLAYER() {

}
void PLAYER::init() {

}
void PLAYER::update() {
	move();
}
void PLAYER::move() {
	if (Abs(Player.advSpeed.x) < Player.maxSpeed.x) {
		if (isPress(KEY_A)) {
			Player.advSpeed.x -= Player.accel.x;
		}
		else if (isPress(KEY_D)) {
			Player.advSpeed.x += Player.accel.x;
		}
	}
	if (Abs(Player.advSpeed.y < Player.maxSpeed.y)) {
		if (isPress(KEY_K)) {
			Player.advSpeed -= Player.accel.y;
		}
		Player.advSpeed += Player.gravity;
	}
	Player.advSpeed.x = Player.advSpeed.x * (1 - (Player.reductionRate.x / Abs(Player.advSpeed.x)));
	Player.advSpeed.y = Player.advSpeed.y * (1 - (Player.reductionRate.y / Abs(Player.advSpeed.y)));
	Player.posit += Player.advSpeed;
}
void PLAYER::draw() {
	rectMode(CENTER);
	fill(Player.fillColor);
	rect(Player.posit.x, Player.posit.y, Player.wide, Player.high);
}