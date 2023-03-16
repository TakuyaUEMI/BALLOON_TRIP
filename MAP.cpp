#include "MAP.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"libOne.h"
#include"CHARACTER_MANAGER.h"
MAP::MAP(class GAME* game) :
    GAME_OBJECT(game) {
}
MAP::~MAP() {
    if (Map.data) { delete[] Map.data; Map.data = 0; }
}
void MAP::create() {
    Map = game()->container()->data().map;
}
void MAP::init() {
    Map.mapEndFrag = 0;
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", Map.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //サイズ分のdata配列を用意する
    Map.data = new char[fileSize];
    //データを読み込む
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    Map.rows = 0;
    Map.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //最初の行の列数
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//表示すべき列数
    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//ワールドの横幅
    Map.endWorldX = Map.worldWidth - width;//表示できる最後の座標
    Map.wx = 0.0f;//現在表示しているワールド座標
}
void MAP::update() {
    Map.wx += Map.scrollSpeed * delta;
    checkMapEnd();
}
void MAP::draw() {
    if (Map.mapEndFrag == 0) {
        drawDefined();
    }
    else {
        drawAuto();
    }
}
void MAP::drawDefined() {
    int startCol = (int)Map.wx / Map.chipSize;//表示開始列
    int endCol = startCol + Map.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        
        float wx = (float)Map.chipSize * c;
        for (int r = 0; r < Map.rows; r++) {
            float wy = (float)Map.chipSize * r;
            char charaId = Map.data[r * Map.cols + c];
            if (charaId >= 'a' && charaId <= 'z') {
                game()->characterManager()->appear(charaId, wx-Map.wx, wy-Map.wy, 0);
                //game()->characterManager()->appear(charaId, wx - Map.wx, wy - Map.wy);
                Map.data[r * Map.cols + c] = '.';
            }
        }
    }
}
void MAP::drawAuto() {
    Map.advDistance += Map.scrollSpeed * delta;
    if (Map.advDistance > Map.chipSize*2) {
        Map.advDistance = 0;
        float wx = width + Map.chipSize;
        int bal = 0; 
        if (randomInt(20) >= Map.randBalloon) bal = 1;
        int enemy = randomInt(Map.randEnemy);
        int i = 0;
        int frag = 1;
        VECTOR2 vec = VECTOR2(0, 0);
        char id = BALLOON_ID;
        float* wy = new float[bal + enemy];
        while (i < bal + enemy) {
            float tempWy = randomInt(height - Map.chipSize) + Map.chipSize / 2;
            frag = 1;
            for (int j = 0; j < i; j++) {
                if (tempWy > wy[j] - Map.chipSize && tempWy < wy[j] + Map.chipSize * 2) {
                    frag = 0;
                }
            }
            if (frag == 1) {
                wy[i] = tempWy;
                frag = 0;
                if (i < bal) {
                    id = BALLOON_ID;
                }
                else{
                    id = ENEMY_ID;
                    //vec = VECTOR2(0, 0);
                    vec = VECTOR2(randomInt(Map.maxEnemySpeedX) - Map.maxEnemySpeedX / 2,
                       randomInt(Map.maxEnemySpeedY) - Map.maxEnemySpeedY / 2);
                }
                game()->characterManager()->appear(id, wx, tempWy, vec);
                i++;
            }
        }
    delete[] wy;
    }
}
void MAP::checkMapEnd() {
    if ((int)Map.wx / Map.chipSize + Map.dispCols >= Map.cols) {
        Map.mapEndFrag = 1;
    }
}
int MAP::randomInt(int r) {
    return random() % r;
}

