#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "object.h"

using namespace std;

// 게임 상수
const int WIDTH = 200;       // 게임판 너비
const int HEIGHT = 100;      // 게임판 높이
const int VIEW_WIDTH = 50;   // 시야 너비
const int VIEW_HEIGHT = 25;  // 시야 높이
const int INITIAL_LENGTH = 5; // 초기 뱀 길이

// 방향
enum Direction { UP, DOWN, LEFT, RIGHT };

// 게임 상태
bool gameOver;
int score;

// 뱀과 과일
Snake snake(WIDTH / 2, HEIGHT / 2);

// 뱀의 이동 방향
Direction dir;

// 뱀의 꼬리 (꼬리의 위치를 기록하기 위한 벡터)
vector<Snake> tail;

// 게임판
vector<vector<char>> gameBoard;

// 초기화
void Setup() {
    gameOver = false;
    dir = RIGHT;
    score = 0;

    // 게임판 초기화
    gameBoard.resize(WIDTH, vector<char>(HEIGHT, ' '));

    // 뱀의 초기 위치
    snake = Snake(WIDTH / 2, HEIGHT / 2);

    // 초기 꼬리 생성
    for (int i = 0; i < INITIAL_LENGTH - 1; i++) {
        Snake tailSegment(snake.getX() - (i + 1), snake.getY());
        tail.push_back(tailSegment);
    }
}

// 그리기
void Draw() {
    system("cls"); // 화면 지우기

    // 게임판 그리기
    for (int i = 0; i < VIEW_HEIGHT; i++) {
        for (int j = 0; j < VIEW_WIDTH; j++) {
            int mapX = snake.getX() - (VIEW_WIDTH / 2) + j;
            int mapY = snake.getY() - (VIEW_HEIGHT / 2) + i;

            // 테두리인 경우
            if (mapX < 0 || mapX >= WIDTH || mapY < 0 || mapY >= HEIGHT) {
                cout << "#"; // 테두리 라인
            }
            // 게임판 내부
            else if (i == 0 || i == VIEW_HEIGHT - 1 || j == 0 || j == VIEW_WIDTH - 1) {
                cout << "*"; // 테두리
            }
            else {
                // 뱀의 위치
                if (mapX == snake.getX() && mapY == snake.getY()) {
                    cout << "O";
                }
                // 꼬리의 위치
                else {
                    bool isTail = false;
                    for (int k = 0; k < tail.size(); k++) {
                        if (tail[k].getX() == mapX && tail[k].getY() == mapY) {
                            cout << "o";
                            isTail = true;
                            break;
                        }
                    }
                    if (!isTail) {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }

    // 점수 출력
    cout << "Score: " << score << endl;
}

// 입력 처리
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// 게임 로직 업데이트
void Logic() {
    // 꼬리 위치 업데이트
    Snake prevTail = tail[tail.size() - 1];
    for (int i = tail.size() - 1; i > 0; i--) {
        tail[i] = tail[i - 1];
    }
    tail[0] = snake;

    // 뱀의 이동
    switch (dir) {
    case UP:
        snake.setY(snake.getY() - 1);
        break;
    case DOWN:
        snake.setY(snake.getY() + 1);
        break;
    case LEFT:
        snake.setX(snake.getX() - 1);
        break;
    case RIGHT:
        snake.setX(snake.getX() + 1);
        break;
    }

    // 벽에 부딪혔는지 체크
    if (snake.getX() < 0 || snake.getX() >= WIDTH || snake.getY() < 0 || snake.getY() >= HEIGHT)
        gameOver = true;

    // 자기 자신에게 부딪혔는지 체크
    for (int i = 0; i < tail.size(); i++) {
        if (snake.getX() == tail[i].getX() && snake.getY() == tail[i].getY())
            gameOver = true;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        // 게임 속도 조절 (sleep 함수는 windows.h에 포함되어 있습니다.)
        Sleep(100);
    }
    return 0;
}
