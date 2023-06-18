#pragma once

#include"Object.h"
#include<Windows.h>
#include <stdio.h>
#include <conio.h>

#define WIDTH 200        // ������ �ʺ�
#define HEIGHT 100       // ������ ����
#define VIEW_WIDTH 50    // �þ� �ʺ�
#define VIEW_HEIGHT 25   // �þ� ����
#define INITIAL_LENGTH 5 // �� �ʱ� ����
#define MAX_LENGTH 100   // �� �ִ� ����
#define NUM_ASSIGNMENT 100   // �����Ǵ� ���� ����
#define NUM_WALLS 1000   // �����Ǵ� �� ����


char ScreenBuffer[65536]; // �ִ� �޸�

int gameOver;             // ���� ���� ����
int gameState;            // ���� ����
int selectMenu;           // �޴� ����
int play;
 
int mode;                 // ���̵�
int speed;                // ���� ���ǵ�


// d\���� ��� �Ǵ� �� �ƴѰ�





Snake snake;              // ��
char strHead[2];
char snakeHead;           // �� �Ӹ�
Snake tail[MAX_LENGTH];   // ���� ���� (������ ��ġ�� ����ϱ� ���� �迭)
int tailLength;


enum Direction { UP, DOWN, LEFT, RIGHT };// ����
enum Direction dir;       // ���� �̵� ����


/*����*/
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

