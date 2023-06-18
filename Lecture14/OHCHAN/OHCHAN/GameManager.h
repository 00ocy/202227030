#pragma once

#include"Object.h"
#include<Windows.h>
#include <stdio.h>
#include <conio.h>

#define WIDTH 200        // 게임판 너비
#define HEIGHT 100       // 게임판 높이
#define VIEW_WIDTH 50    // 시야 너비
#define VIEW_HEIGHT 25   // 시야 높이
#define INITIAL_LENGTH 5 // 뱀 초기 길이
#define MAX_LENGTH 100   // 뱀 최대 길이
#define NUM_ASSIGNMENT 100   // 생성되는 과제 개수
#define NUM_WALLS 1000   // 생성되는 벽 개수


char ScreenBuffer[65536]; // 최대 메모리

int gameOver;             // 게임 실행 여부
int gameState;            // 게임 상태
int selectMenu;           // 메뉴 선택
int play;
 
int mode;                 // 난이도
int speed;                // 게임 스피드


// d\여기 없어도 되는 거 아닌가





Snake snake;              // 뱀
char strHead[2];
char snakeHead;           // 뱀 머리
Snake tail[MAX_LENGTH];   // 뱀의 꼬리 (꼬리의 위치를 기록하기 위한 배열)
int tailLength;


enum Direction { UP, DOWN, LEFT, RIGHT };// 방향
enum Direction dir;       // 뱀의 이동 방향


/*학점*/
int AssignmentNum;
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
char strAssignment[4];
char strJumsu[10];

