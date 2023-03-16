#pragma once
#include"TITLE.h"
#include"FIXED_STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"BALLOONS.h"
#include"MAP.h"
#include"CHARACTER.h"
#include"ENEMY.h"
#include"SCORE.h"
#include"CHARACTER_MANAGER.h"
class CONTAINER
{
private:
	//データは全てここに集まる
	struct DATA {
		TITLE::DATA title;
		FIXED_STAGE::DATA fs;
		MAP::DATA map;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;
		CHARACTER_MANAGER::DATA charaManager;
		PLAYER::DATA player;
		CHARACTER::DATA playerCharacter;
		BALLOONS::DATA balloons;
		CHARACTER::DATA balloonsCharacter;
		SCORE::DATA score;
		ENEMY::DATA enemy;
		CHARACTER::DATA enemyCharacter;
	};
	DATA D;
public:
	CONTAINER();
	~CONTAINER();
	void load();
		void setData();
			void setTitle();
			void setFixedStage();
			void setMap();
			void setGameClear();
			void setGameOver();
			void setCharaManager();
			void setPlayer();
			void setBalloons();
			void setEnemy();
			void setScore();
		void loadGraphic();
	//getter
	const DATA& data() { return D; }
};

