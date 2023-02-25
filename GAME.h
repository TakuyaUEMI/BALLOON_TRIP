#pragma once
class GAME
{
//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }

//�V�[��
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
	class MAP* Map;
	SCENE_ID CurSceneId;
public:
	class MAP* map() { return Map; }
	void changeScene(SCENE_ID sceneId);

//�L�����N�^�[
private:
	class CHARACTER_MANAGER* CharacterManager;
public:
	class CHARACTER_MANAGER* characterManager() { return CharacterManager; }

//�R���X�g���N�^�Ƃ�
public:
	GAME();
	~GAME();
	void run();
};

