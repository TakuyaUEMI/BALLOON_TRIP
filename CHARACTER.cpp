#include "CHARACTER.h"
#include"libOne.h"
char d[4];
CHARACTER::CHARACTER(class GAME* game):
	GAME_OBJECT(game){
}
CHARACTER::~CHARACTER() {

}
void CHARACTER::create() {
	strcpy_s(d, "ddd");
}
void CHARACTER::init() {

}
void CHARACTER::appear(float wx,float wy,VECTOR2 vec) {

}
void CHARACTER::update() {

}
void CHARACTER::draw() {
	print(d);
}