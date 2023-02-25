#pragma once
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"BALLOONS.h"
#include"MAP.h"
#include"CHARACTER.h"
class CONTAINER
{
private:
	struct DATA {
		TITLE::DATA title;
		MAP::DATA map;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;
		PLAYER::DATA player;
		CHARACTER::DATA playerCharacter;
		BALLOONS::DATA balloons;
		CHARACTER::DATA balloonsCharacter;
	};
	DATA D;
public:
	CONTAINER();
	~CONTAINER();
	void load();
		void setData();
			void setTitle();
			void setMap();
			void setGameClear();
			void setGameOver();
			void setPlayer();
			void setBalloons();
		void loadGraphic();
	const DATA& data() { return D; }
};

