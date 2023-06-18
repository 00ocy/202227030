#pragma once

#include"Object.h"
#include<Windows.h>

#define WIDTH 200        // ������ �ʺ�
#define HEIGHT 100       // ������ ����
#define VIEW_WIDTH 50    // �þ� �ʺ�
#define VIEW_HEIGHT 25   // �þ� ����
#define INITIAL_LENGTH 5 // �� �ʱ� ����
#define MAX_LENGTH 100   // �� �ִ� ����
#define NUM_FRUITS 100   // �����Ǵ� ����
#define NUM_WALLS 1000   // �����Ǵ� ��

char ScreenBuffer[65536]; // �ִ� �޸�
// ������
void InputBuffer();
char gameBoard[WIDTH][HEIGHT];
void Stage();
void ReSet();



// ��ü��
int gameState;
int menuSelect;
void setCursorPos(int x, int y);
void SetColor(unsigned short backgroundColor, unsigned short textColor);

// ���̵�
int mode;
int speed;
DWORD WINAPI updateFruitShapes(LPVOID arg);


// ��
Snake snake;
// ���� ���� (������ ��ġ�� ����ϱ� ���� �迭)
Snake tail[MAX_LENGTH];
int tailLength;
// ��Ӹ�
char snakeHead; //�����Ҷ� �ٲ��ִ°ɷ�

char strHead[2];
void stringHead();



/*����*/ // ���� �浹�� ���� �������
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


// �ָ�
void setScreenSize(int width, int height);
void ClearBuffer();
int WriteToBuffer(int x, int y, const char* str);
void handleFruitCollision();
void handleWallCollision();
void generateFruits();
void generateWalls();

// ����
enum Direction { UP, DOWN, LEFT, RIGHT };

// ���� ����
int gameOver;
int selectMenu;
// ���� �̵� ����
enum Direction dir;

void Setup();
int DrawBuffer();
void Input();
void Logic();
void Update();
