#pragma once
#include "GAME_OBJECT.h"
#include"VECTOR2.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        int chipSize = 0; //正方形マップチップ画像の一辺のドット数
        char* data = 0; //データ配列のポインタ
        int cols = 0; //データの列数
        int rows = 0; //データの行数
        int dispCols = 0;
        int dispRows = 0;
        float scrollSpeed = 0;
        float wx = 0;//world position x
        float wy = 0;//world position y
        float worldWidth = 0;
        float worldHeight = 0;
        float endWorldX = 0;
        float endWorldY = 0;
        float centerX = 0;
        int mapEndFrag = 0;

        int randBalloon;
        int randEnemy;
        float maxEnemySpeedX;
        float maxEnemySpeedY;
        float advDistance = 0;
    };
    enum CHARA_ID {
        PLAYER_ID = 'p',
        BALLOON_ID = 'b',
        ENEMY_ID = 'e',
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void update();
    void draw();
    void drawDefined();
    void drawAuto();
    void checkMapEnd();
    int randomObject(int r);
    float wx() { return Map.wx; }
    float wy() { return Map.wy; }
    int chipSize() { return Map.chipSize; }
    int scrollSpeed() { return Map.scrollSpeed; }
};

