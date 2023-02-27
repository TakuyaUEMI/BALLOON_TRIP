#include "PLAYER.h"
#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
PLAYER::~PLAYER() {

}
void PLAYER::create(){
	Player = game()->container()->data().player;
	Character = game()->container()->data().playerCharacter;
	
}
void PLAYER::init() {

}
void PLAYER::appear(float wx,float wy,VECTOR2 vec) {
	Character.posit.x = wx - game()->map()->wx() + Player.wide / 2;
	Character.posit.y = wy - game()->map()->wx() + Player.high / 2;
}
void PLAYER::update() {
	move();
	Player.invicibleRestTime -= delta;
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
	Character.posit += Player.advSpeed;
	if (Character.posit.x < Player.wide / 2) {
		Character.posit.x = Player.wide / 2;
		Player.advSpeed.x = 0;
	}
	else if (Character.posit.x > width - Player.wide / 2) {
		Character.posit.x = width - Player.wide / 2;
		Player.advSpeed.x = 0;
	}
	if (Character.posit.y < Player.high / 2) {
		Character.posit.y = Player.high / 2;
		Player.advSpeed.y = 0;
	}
	else if (Character.posit.y > height - Player.high / 2) {
		Character.posit.y = height - Player.high / 2;
		Player.advSpeed.y = 0;
	}

}
void PLAYER::draw() {
	rectMode(CENTER);
	print(Player.hp);
	fill(Player.fillColor);
	rect(Character.posit.x, Character.posit.y, Player.wide, Player.high);
}
void PLAYER::damage() {
	if (Player.invicibleRestTime <= 0) {
		Player.hp--;
		Player.invicibleRestTime = Player.invicibleTime;
	}
}
