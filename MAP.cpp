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
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    Map.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    Map.rows = 0;
    Map.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //�ŏ��̍s�̗�
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//�\�����ׂ���
    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//���[���h�̉���
    Map.endWorldX = Map.worldWidth - width;//�\���ł���Ō�̍��W
    Map.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
}
void MAP::update() {
    Map.wx += Map.scrollSpeed * delta;
}
void MAP::draw() {
    int startCol = (int)Map.wx / Map.chipSize;//�\���J�n��
    int endCol = startCol + Map.dispCols;//�\���I����
    for (int c = startCol; c < endCol; c++) {
        
        float wx = (float)Map.chipSize * c;
        for (int r = 0; r < Map.rows; r++) {
            float wy = (float)Map.chipSize * r;
            char charaId = Map.data[r * Map.cols + c];
            if (charaId >= 'a' && charaId <= 'z') {
                game()->characterManager()->appear(charaId, wx, wy);
                //game()->characterManager()->appear(charaId, wx - Map.wx, wy - Map.wy);
                Map.data[r * Map.cols + c] = '.';
            }
        }
    }
}