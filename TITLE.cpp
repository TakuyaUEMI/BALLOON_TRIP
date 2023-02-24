#include "TITLE.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
TITLE::TITLE(class GAME* game):
	SCENE(game){
}
TITLE::~TITLE() {

}
void TITLE::create() {
	Title = game()->container()->data().title;
}
void TITLE::draw() {
	clear(Title.backColor);
}
void TITLE::nextScene() {

}