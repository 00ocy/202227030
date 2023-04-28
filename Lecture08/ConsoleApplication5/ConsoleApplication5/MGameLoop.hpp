#pragma once 
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13

namespace MuSoeun
{
	void gotoxy(int x, int y)
	{
		//x, y 좌표 설정
		COORD pos = { x,y };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetCursorState(bool visible) //커서 안 보이게 하기
	{
		/*CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = visible;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);*/
	}


	class MGameLoop
	{
	public:
		MGameLoop() {}
		~MGameLoop() {} 

		bool isGameRunning = false;    //게임실행 체크
		bool exitselect = false;       //ESC눌렀을때 체크
		bool OnOff = true;             //끄냐 마냐 체크

		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 15);
			std::cout << ANSI_COLOR_RESET"게임 초기화중" << std::endl;
			isGameRunning = true;
			exitselect = true;
		}

		void Release()
		{
			system("cls");
			gotoxy(5, 7);
			std::cout << ANSI_COLOR_RESET"종료하시겠습니까?" << std::endl;
			std::cout << "               " << std::endl;
			std::cout << ANSI_COLOR_YELLOW"     [ 예 ]";
			std::cout << ANSI_COLOR_RESET"   [ 아니오 ]" << std::endl;
			
			while (exitselect)
			{
				if (_kbhit()){	KeyEvent2(_getch()); }
			}						
		}

		void Update()
		{
			gotoxy(3, 16);
			std::cout << ANSI_COLOR_RESET"게임 키입력 대기" << std::endl;

			if (_kbhit()){ KeyEvent(_getch()); }						
		}

		void Render()
		{
			gotoxy(3, 17);
			std::cout << ANSI_COLOR_RESET"게임 화면 그리기" << std::endl;
		}

		void Run()
		{
			system("cls");
			Initialize();
			while (isGameRunning)
			{
				Update();
				Render();
			}
			Release();
		}

		void KeyEvent(char KeyInput)
		{
			switch (KeyInput)
			{
			case KEY_ESC:
				gotoxy(5, 5);
				Release();
				break;

			case KEY_LEFT:				
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_RED"왼쪽 눌림  " << std::endl;
				break;

			case KEY_RIGHT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_GREEN"오른쪽 눌림" << std::endl;
				break;

			case KEY_ENTER:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_BLUE"엔터 눌림  " << std::endl;
				break;

			default:
				isGameRunning = true;
				break;
			}			
		}

		void KeyEvent2(char KeyInput2)
		{
			switch (KeyInput2)
			{
				case KEY_LEFT:
					gotoxy(5, 9);
					std::cout << ANSI_COLOR_YELLOW"[ 예 ]";
					std::cout << ANSI_COLOR_RESET"   [ 아니오 ]" << std::endl;
					OnOff = true;					
					break;

				case KEY_RIGHT:
					gotoxy(5, 9);
					std::cout << ANSI_COLOR_RESET"[ 예 ]";
					std::cout << ANSI_COLOR_YELLOW"   [ 아니오 ]" << std::endl;
					OnOff = false;					
					break;
			
				case KEY_ENTER:
					if (OnOff)
					{
						exitselect = false;
						isGameRunning = false;
					}
					else{ Run(); }
					break;

				default:
					isGameRunning = true;
					break;					
			}
		}		
	};
}