//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

// game_state == 0 일때
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;
#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y)
{
    //x, y 좌표 설정
    COORD pos = { x,y };

    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// game_state == 1 일때
int print_game_screen(int stage_width, int stage_height)
{
    system("cls");

    //위쪽 벽 - width 만큼 *(벽) 출력 후 줄바꿈
    for (int i = 0; i < stage_width; i++)
    {
        std::cout <<"*";
    }

    std::cout<<std::endl;

    //양쪽 벽 - 위,아래 벽을 제외한 (height-2)줄 만큼 *(벽) width-2 만큼의 공백 *(벽) 줄바꿈 반복
    for (int i = 0; i < stage_height-2; i++)
    {
        std::cout << "*";

        for (int i = 0; i < stage_width-2; i++)
        {
            std::cout << " ";
        }

        std::cout << "*"<<std::endl;
    }

    //아래쪽 벽 - width 만큼 *(벽) 출력
    for (int i = 0; i < stage_width; i++)
    {
        std::cout << "*";
    }

    gotoxy(stage_width ,stage_height);
    
    return 0;
}

// game_state == 2 일때
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*       Ooo 지렁이 키우기 게임 ooo       *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*   @를 먹으며 커지는 지렁이를 조작하여  *" << std::endl;
    std::cout << "*   최대한 크게 키워보세요!              *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;

    return 0;
}

int main()
{   
    int game_state = 0;
    int is_game_running = 1;

    while (is_game_running)
    {
        char key_input = '0';

        switch (game_state)
        {
            case 0:
                print_title_screen();
                key_input = _getch();

        goto1:  switch (key_input)
                {
                    case '1':
                        game_state = 1;
                        break;

                    case '2':
                        game_state = 2;
                        break;

                    case '3':
                        break;

                    case '4':
                        is_game_running = 0;
                        break;

                    case 27:
                        is_game_running = 0;
                        break;

                    default:
                        while (key_input!=49 && key_input != 50 && key_input != 51 && key_input != 52 && key_input != 27)
                        {
                            key_input = _getch();
                        }
                        goto goto1;
                }
            break;

        case 1:
            print_game_screen(30, 15);
            key_input = _getch();
            
        case 2:
            system("cls");
            print_introduction_screen();
            key_input = _getch();
    goto2:  switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                while (key_input != 89 && key_input != 121 && key_input != 78 && key_input != 110)
                {
                    key_input = _getch();
                }
                goto goto2;
                break;
            }

        default:
            break;
        }

    }
    return 0;
}