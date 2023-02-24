#pragma once
class GAME
{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }

//シーン
public:
	enum SCENE_ID {
		TITLE_ID,
		FIXED_STAGE_ID,
		AUTO_STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);

//キャラクター
private:
	class PLAYER* Player;
public:
	void draw();
	class PLAYER* player() { return Player; }

//コンストラクタとか
public:
	GAME();
	~GAME();
	void run();
};

