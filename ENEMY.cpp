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
}
void ENEMY::init() {

}
void ENEMY::appear(float wx, float wy) {
	Enemy.posit.x = wx - game()->map()->wx() + Enemy.wide / 2;
	Enemy.posit.y = wy - game()->map()->wx() + Enemy.high / 2;
}
void ENEMY::update() {
	move();
}
void ENEMY::move() {
	Enemy.posit += Enemy.advSpeed;
}
void ENEMY::draw() {
	rectMode(CENTER);
	fill(Enemy.fillColor);
	rect(Enemy.posit.x, Enemy.posit.y, Enemy.wide, Enemy.high);
	rect(Enemy.posit.x, Enemy.posit.y, Enemy.wide, Enemy.high, Enemy.angle);
}