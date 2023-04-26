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
	void gotoxy(int x, int y) {
		//x, y ��ǥ ����
		COORD pos = { x,y };
		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetCursorState(bool visible)
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

		bool isGameRunning = false;
		bool OnOff = false;

		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 15);
			std::cout << ANSI_COLOR_RESET"���� �ʱ�ȭ��" << std::endl;
			isGameRunning = true;
			OnOff = true;
		}
		void Release()
		{
			gotoxy(5, 5);
			std::cout << ANSI_COLOR_RESET"�����Ͻ�dddddddd�ڽ��ϱ�?" << std::endl;
			std::cout << "               " << std::endl;
			std::cout << "     [ �� ]   [ �ƴϿ� ]" << std::endl;
						
		}

		void Update()
		{
			gotoxy(3, 16);
			std::cout << ANSI_COLOR_RESET"���� Ű�Է� ���" << std::endl;
			if (_kbhit())
			{
				KeyEvent(_getch());
			}						
		}

		void Render()
		{
			gotoxy(3, 17);
			std::cout << ANSI_COLOR_RESET"���� ȭ�� �׸���" << std::endl;
		}

		void Run()
		{
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
				std::cout << ANSI_COLOR_RESET"ESC ����         " << std::endl;

				gotoxy(5, 7);
				std::cout << ANSI_COLOR_RESET"�����Ͻðڽ��ϱ�?" << std::endl;
				std::cout << "               " << std::endl;
				std::cout << "     [ �� ]   [ �ƴϿ� ]" << std::endl;
				
				while (OnOff)
				{
					if (_kbhit())
					{						
						KeyEvent2(_getch());
					}
				}
				break;

			case KEY_LEFT:
				
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_RED"���� ����  " << std::endl;
				break;
			case KEY_RIGHT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_GREEN"������ ����" << std::endl;
				break;
			case KEY_ENTER:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_BLUE"���� ����  " << std::endl;
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
					std::cout << ANSI_COLOR_YELLOW"[ �� ]";
					std::cout << ANSI_COLOR_RESET"   [ �ƴϿ� ]" << std::endl;
					
					while (OnOff)
					{
						if (_kbhit()&&_getch() == KEY_ENTER)
						{
							OnOff = false;
							isGameRunning = false;
						}
					}
					break;

				case KEY_RIGHT:
					gotoxy(5, 9);
					std::cout << ANSI_COLOR_RESET"[ �� ]";
					std::cout << ANSI_COLOR_YELLOW"   [ �ƴϿ� ]" << std::endl;
					
					break;
			
				default:
					isGameRunning = true;
					break;
					
			}
		}
		
	};

}