#include "GAME_OVER.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {

}
void GAME_OVER::create() {
	GameOver = game()->container()->data().gameOver;
}
void GAME_OVER::draw() {
	clear(GameOver.backColor);
	game()->characterManager()->draw();
	game()->score()->draw();

	fill(GameOver.overTextColor);
	textSize(GameOver.overTextSize);
	text(GameOver.overTextStr, GameOver.overTextPosit.x, GameOver.overTextPosit.y);

	fill(GameOver.continueTextColor);
	textSize(GameOver.continueTextSize);
	text(GameOver.continueStr, GameOver.continueTextPosit.x, GameOver.continueTextPosit.y);
	text(GameOver.continueStr2, GameOver.continueTextPosit.x, GameOver.continueTextPosit.y+GameOver.continueTextSize);

}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::FIXED_STAGE_ID);
	}
	if (isTrigger(KEY_ENTER)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}