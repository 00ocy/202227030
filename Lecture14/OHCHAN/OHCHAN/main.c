
#include "Game.h"


int main() {
unsigned long time_end = GetTickCount64();
unsigned long deltaTime = GetTickCount64();
    Setup();
    while (!gameOver) {

        DrawBuffer();
        deltaTime = GetTickCount64() - time_end;
        time_end = GetTickCount64();
        if (deltaTime < 16)
            Sleep(16 - deltaTime);

        if (deltaTime != 0)
      //      printf("time : %d \nfps :%d\n", deltaTime, 1000 / deltaTime);
        Input();
        Logic();

        // 게임 속도 조절 (Sleep 함수는 windows.h에 포함되어 있습니다.)
        Sleep(speed);
    }
    return 0;
}


// 시작
void Setup() {

    // 게임 오버 여부
    gameOver = 0;

    // 게임 상태 (메인메뉴)
    gameState = 0;

    // 메인 메뉴 스크린사이즈 설정
    setScreenSize(70, 20);

    // 테두리 그리기
    ClearBuffer();

    // 뱀 머리를 O 로 설정
    snakeHead = 'O';
   
}


// 출력
int DrawBuffer(){

    setCursorPos(0, 0);
    printf("%s", ScreenBuffer);
    return 0;
}

// 입력 처리
void Input() {
    if (gameState == 0) mainMenu_Input();
    if (gameState == 1) gamePlay_Input();
    if (gameState == 2) gameDescription_Input();
    if (gameState == 3) option_Input();
    if (gameState == 4) playerDeath_Input();
}

// 게임 로직 업데이트
void Logic() {
    if(gameState==0) mainMenu_Logic();
    if(gameState==1) gamePlay_Logic();
    if(gameState==2) gameDescription_Logic();
    if(gameState==3) option_Logic();
    if(gameState==4) playerDeath_Logic();
}

