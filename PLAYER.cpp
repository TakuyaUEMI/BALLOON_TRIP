#include "PLAYER.h"
#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
PLAYER::PLAYER(class GAME* game):
	CHARACTER(game){
}
PLAYER::~PLAYER() {

}
void PLAYER::create() {
	Player = game()->container()->data().player;
	Character = game()->container()->data().playerCharacter;
}
void PLAYER::init() {

}
void PLAYER::appear(float wx,float wy) {
	Player.posit.x = wx;
	Player.posit.y = wy;
}
void PLAYER::update() {
	move();
}
void PLAYER::move() {
	if (Abs(Player.advSpeed.x) < Player.maxSpeed.x) {
		if (isPress(KEY_A)) {
			Player.advSpeed.x -= Player.accel.x * delta;
		}
		else if (isPress(KEY_D)) {
			Player.advSpeed.x += Player.accel.x * delta;
		}
	}
	if (Abs(Player.advSpeed.y < Player.maxSpeed.y)) {
		if (isPress(KEY_K)) {
			Player.advSpeed.y -= Player.accel.y * delta;
		}
		Player.advSpeed.y += Player.gravity * delta;
	}
	Player.advSpeed.x *= Player.reductionRatio;
	Player.posit += Player.advSpeed;
	if (Player.posit.x < Player.wide / 2) {
		Player.posit.x = Player.wide / 2;
		Player.advSpeed.x = 0;
	}
	else if (Player.posit.x > width - Player.wide / 2) {
		Player.posit.x = width - Player.wide / 2;
		Player.advSpeed.x = 0;
	}
	if (Player.posit.y < Player.high / 2) {
		Player.posit.y = Player.high / 2;
		Player.advSpeed.y = 0;
	}
	else if (Player.posit.y > height - Player.high / 2) {
		Player.posit.y = height - Player.high / 2;
		Player.advSpeed.y = 0;
	}

}
void PLAYER::draw() {
	rectMode(CENTER);
	fill(Player.fillColor);
	rect(Player.posit.x, Player.posit.y, Player.wide, Player.high);
	//debug
	printSize(100);
	print(Player.posit.x);
	print(Player.posit.y);
}
