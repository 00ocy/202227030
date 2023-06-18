#pragma once

#include"Object.h"
#include<Windows.h>

#define WIDTH 200        // 게임판 너비
#define HEIGHT 100       // 게임판 높이
#define VIEW_WIDTH 50    // 시야 너비
#define VIEW_HEIGHT 25   // 시야 높이
#define INITIAL_LENGTH 5 // 뱀 초기 길이
#define MAX_LENGTH 100   // 뱀 최대 길이
#define NUM_FRUITS 100   // 생성되는 과제
#define NUM_WALLS 1000   // 생성되는 벽

char ScreenBuffer[65536]; // 최대 메모리
// 게임판
void InputBuffer();
char gameBoard[WIDTH][HEIGHT];
void Stage();
void ReSet();



// 전체적
int gameState;
int menuSelect;
void setCursorPos(int x, int y);
void SetColor(unsigned short backgroundColor, unsigned short textColor);

// 난이도
int mode;
int speed;
DWORD WINAPI updateFruitShapes(LPVOID arg);


// 뱀
Snake snake;
// 뱀의 꼬리 (꼬리의 위치를 기록하기 위한 배열)
Snake tail[MAX_LENGTH];
int tailLength;
// 뱀머리
char snakeHead; //시작할때 바꿔주는걸로

char strHead[2];
void stringHead();



/*학점*/ // 학점 충돌과 같은 헤더파일
int Lecture;
int A;
int B;
int C;
int Progress;


double Hakjum;
double jumsu;


char strA[4];
char strB[4];
char strC[4];
char strProgress[4];
char strLecture[4];
char strJumsu[10];


// 애매
void setScreenSize(int width, int height);
void ClearBuffer();
int WriteToBuffer(int x, int y, const char* str);
void handleFruitCollision();
void handleWallCollision();
void generateFruits();
void generateWalls();

// 방향
enum Direction { UP, DOWN, LEFT, RIGHT };

// 게임 상태
int gameOver;
int selectMenu;
// 뱀의 이동 방향
enum Direction dir;

void Setup();
int DrawBuffer();
void Input();
void Logic();
void Update();
