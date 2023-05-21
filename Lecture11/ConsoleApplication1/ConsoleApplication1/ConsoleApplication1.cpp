#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

const int BUFFER_SIZE = 10;

vector<vector<char>> screenBuffer(BUFFER_SIZE, vector<char>(BUFFER_SIZE, ' '));
int cursorX = 0;
int cursorY = 0;

void Update()
{
    // 스크린 버퍼에 단어 추가
    if (cursorX < BUFFER_SIZE && cursorY < BUFFER_SIZE)
    {
        screenBuffer[cursorY][cursorX] = 'a';
    }

    // 커서 위치 업데이트
    cursorX++;
    if (cursorX >= BUFFER_SIZE)
    {
        cursorX = 0;
        cursorY++;
        if (cursorY >= BUFFER_SIZE)
        {
            cursorY = 0;
        }
    }
}

void Render()
{
    // 스크린 버퍼 출력
    for (int y = 0; y < BUFFER_SIZE; y++)
    {
        for (int x = 0; x < BUFFER_SIZE; x++)
        {
            cout << screenBuffer[y][x];
        }
        cout << endl;
    }
}

int main()
{
    while (true)
    {
        // 업데이트
        Update();

        // 렌더링
        Render();

        // "m" 키 입력 처리
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'm')
            {
                // 마지막에 출력된 글자부터 지우기
                int lastX = (BUFFER_SIZE + cursorX - 1) % BUFFER_SIZE;
                int lastY = (BUFFER_SIZE + cursorY - 1) % BUFFER_SIZE;
                screenBuffer[lastY][lastX] = ' ';
            }
        }

        // 0.5초 대기
        this_thread::sleep_for(chrono::milliseconds(500));

        // 화면 클리어
        system("cls");
    }

    return 0;
}
