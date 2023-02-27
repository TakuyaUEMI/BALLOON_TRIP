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
	
	fill(Title.titleTextColor);
	textSize(Title.titleTextSize);
	text(Title.titleStr, Title.titlePosit.x, Title.titlePosit.y);
	
	fill(Title.manualTextColor);
	textSize(Title.manualTextSize);
	text(Title.manualStr, Title.manualPosit.x, Title.manualPosit.y);

	fill(Title.startTextColor);
	textSize(Title.startTextSize);
	text(Title.startStr, Title.startPosit.x, Title.startPosit.y);
	
}
void TITLE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::FIXED_STAGE_ID);
	}
}