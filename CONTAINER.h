#pragma once
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;
		PLAYER::DATA player;
	};
	DATA D;
public:
	CONTAINER();
	~CONTAINER();
	void load();
		void setData();
			void setTitle();
			void setGameClear();
			void setGameOver();
			void setPlayer();
		void loadGraphic();
	const DATA& data() { return D; }
};

