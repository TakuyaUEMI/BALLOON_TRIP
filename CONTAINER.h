#pragma once
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;
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
		void loadGraphic();
	const DATA& data() { return D; }
};

