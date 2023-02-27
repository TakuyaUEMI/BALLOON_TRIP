#include "ENEMY.h"
#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
ENEMY::ENEMY(class GAME* game):
	CHARACTER(game){
}
ENEMY::~ENEMY() {

}
void ENEMY::create() {
	Enemy = game()->container()->data().enemy;
	Character = game()->container()->data().enemyCharacter;
}
void ENEMY::init() {
	Character.active = 0;
	Character.posit = VECTOR2(-100, -100);
}
void ENEMY::appear(float wx, float wy,VECTOR2 vec) {
	Character.posit.x = wx + Enemy.wide / 2;
	Character.posit.y = wy + Enemy.high / 2;
	Character.active = 1;
	Enemy.advSpeed = vec;
}
void ENEMY::update() {
	move();
}
void ENEMY::move() {
	Character.posit += Enemy.advSpeed * delta;
	Enemy.angle += Enemy.angleSpeed * delta;
	Character.posit.x -= game()->map()->scrollSpeed()*delta;
	if (Character.posit.x < -Enemy.wide) Character.active = 0;
}
void ENEMY::draw() {
	rectMode(CENTER);
	fill(Enemy.fillColor);
	rect(Character.posit.x, Character.posit.y, Enemy.wide, Enemy.high);
	rect(Character.posit.x, Character.posit.y, Enemy.wide, Enemy.high, Enemy.angle);
}