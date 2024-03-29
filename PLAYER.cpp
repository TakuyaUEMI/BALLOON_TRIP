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
	Player.hp = Player.initHp;
	Player.advSpeed = VECTOR2(0, 0);
	Character.posit = VECTOR2(0, 0);
	Player.invicibleRestTime = Player.invicibleTime;
	flyFrag = 0;
}
void PLAYER::appear(float wx,float wy,VECTOR2 vec) {
	Character.posit.x = wx - game()->map()->wx() + Player.wide / 2;
	Character.posit.y = wy - game()->map()->wx() + Player.high / 2;
}
void PLAYER::update() {
	move();
	Player.invicibleRestTime -= delta;
	if (flyFrag == 0) Player.advSpeed.y = 0;//最初、上昇キーを押さない限りは落ちない
	if (Character.posit.y >= height + Player.high / 2) Player.hp = 0;
}
void PLAYER::move() {
	//プレイヤーの位置を決める
	Character.posit += Player.advSpeed * delta;
	//水平方向の速度を決める
	if (Abs(Player.advSpeed.x) <= Player.maxSpeed.x) {
		if (isPress(KEY_A)) {
			Player.advSpeed.x -= Player.accel.x * delta;
		}
		else if (isPress(KEY_D)) {
			Player.advSpeed.x += Player.accel.x * delta;
		}
	}
	//鉛直方向の速度を決める
	if (isTrigger(KEY_K)) {
		Player.advSpeed.y -= Player.triggerAccelY;
		flyFrag = 1;//上昇キーを押したら鉛直方向速度が有効になる
	}
	if (isPress(KEY_K)) {
		Player.advSpeed.y -= Player.accel.y * delta;
	}
	Player.advSpeed.y += Player.gravity * delta;
	if (Player.advSpeed.y > Player.maxSpeed.y) {
		Player.advSpeed.y = Player.maxSpeed.y;
	}
	else if (Player.advSpeed.y < -Player.maxSpeed.y) {
		Player.advSpeed.y = -Player.maxSpeed.y;
	}
	//水平方向の速度を減衰させる
	Player.advSpeed.x *= Player.reductionRatio;
	//画面外に行かないようにする
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
}
void PLAYER::draw() {
	rectMode(CENTER);
	fill(Player.fillColor);
	rect(Character.posit.x, Character.posit.y, Player.wide, Player.high);
}
void PLAYER::damage() {
	if (Player.invicibleRestTime <= 0) {
		Player.hp--;
		Player.invicibleRestTime = Player.invicibleTime;
	}
}
