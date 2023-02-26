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

}
void ENEMY::appear(float wx, float wy) {
	Character.posit.x = wx - game()->map()->wx() + Enemy.wide / 2;
	Character.posit.y = wy - game()->map()->wx() + Enemy.high / 2;
	Character.active = 1;
}
void ENEMY::update() {
	move();
}
void ENEMY::move() {
	Character.posit += Enemy.advSpeed;
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