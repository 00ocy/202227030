#pragma once

#include "Input.h"


void mainMenu_Input()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            selectMenu -= 1;
            
            break;
        case 's':
            selectMenu += 1;
          
            break;
        case 'W':
            selectMenu -= 1;
           
            break;
        case 'S':
            selectMenu += 1;
            
            break;

        case 13:
            if (selectMenu == 1)
            {
                PlayStart();

                gameState = 1;
               
            }
            else if (selectMenu == 2)
            {
                gameState = 2;
                ClearBuffer();
            }
            else if (selectMenu == 3) gameOver = 1;
            else if (selectMenu == 4)
            {
                gameState = 3;
                ClearBuffer();

            }
            break;
        }
    }
    

}

void gamePlay_Input()
{

    if (gameState == 1)
    {
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
            case 'W':
                dir = UP;
                break;
            case 'S':
                dir = DOWN;
                break;
            case 'A':
                dir = LEFT;
                break;
            case 'D':
                dir = RIGHT;
                break;
            }
        }
    }
}

void gameDescription_Input()
{
    if (gameState == 2)
    {
        if (_kbhit()) {
            switch (_getch()) {
            case 'x':
                gameState = 0;
                ClearBuffer();
                break;
            case 'X':
                gameState = 0;
                ClearBuffer();
                break;
            }
        }
    }
}

void option_Input()
{

    if (gameState == 3)
    {

        if (_kbhit()) {
            switch (_getch()) {
            case 'w':
                selectMenu -= 1;
                if (selectMenu <= 0) selectMenu = 2;
                break;
            case 's':
                selectMenu += 1;
                if (selectMenu >= 3) selectMenu = 1;
                break;
            case 'x':
                gameState = 0;
                selectMenu = 4;
                ClearBuffer();
                break;
            case 'W':
                selectMenu -= 1;
                if (selectMenu <= 0) selectMenu = 2;
                break;
            case 'S':
                selectMenu += 1;
                if (selectMenu >= 3) selectMenu = 1;
                break;
            case 'X':
                gameState = 0;
                selectMenu = 4;
                ClearBuffer();
                break;
            case 13:
                if (selectMenu == 1)
                {
                    mode++;
                    if (mode >= 3) mode = 0;
                    ClearBuffer();
                }
                else if (selectMenu == 2)
                {
                    snakeHead++;
                    ClearBuffer();
                }
            }
        }
    }
}

void playerDeath_Input()
{

    if (gameState == 4)
    {
        if (_kbhit()) {
            switch (_getch()) {

            case 'x':
                PlayStart();
                break;

            case 'X':
                PlayStart();
                break;
            }
        }

    }
}