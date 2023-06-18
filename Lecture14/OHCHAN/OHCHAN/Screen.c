#pragma once

#include "Screen.h"

/* 화면 가로세로 설정*/
int screenWidth = 80;
int screenHeight = 25;

// 화면 또는 전체
void setScreenSize(int width, int height)
{
    screenWidth = width;
    screenHeight = height;
}

/* 메뉴화면 버퍼*/
void ClearBuffer()
{
    int y = 0;
    while (y < screenHeight + 2)
    {
        int x = 0;
        while (x < screenWidth + 2)
        {
            if (y == 0 || y == (screenHeight + 1))
                ScreenBuffer[x + (y * (screenWidth + 3))] = '-';
            else
            {
                if (x == 0 || x == (screenWidth + 1))
                    ScreenBuffer[x + (y * (screenWidth + 3))] = '|';
                else
                    ScreenBuffer[x + (y * (screenWidth + 3))] = ' ';
            }
            x = x + 1;
        }
        ScreenBuffer[x + (y * (screenWidth + 3))] = '\n';
        y = y + 1;
    }
    ScreenBuffer[(y * (screenWidth + 3))] = '\0'; 
}

/*버퍼 안에 글씨쓰기*/
int WriteToBuffer(int x, int y, const char* str)
{
    int i = 0;

    while (i < strlen(str))
    {
        ScreenBuffer[x + (y * (screenWidth + 3)) + i] = str[i];
        i = i + 1;
    }

    return 0;
}

void score()
{
    jumsu = Hakjum / AssignmentNum;
    snprintf(strJumsu, sizeof(strJumsu), "%.2f", jumsu);
    snprintf(strA, sizeof(strA), "%d", A);
    snprintf(strB, sizeof(strB), "%d", B);
    snprintf(strC, sizeof(strC), "%d", C);
    snprintf(strProgress, sizeof(strProgress), "%d", Progress);
    snprintf(strAssignment, sizeof(strAssignment), "%d", AssignmentNum);

}

