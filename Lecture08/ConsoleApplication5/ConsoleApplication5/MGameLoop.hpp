#pragma once //#define _IS_THIS_HEADER_INCLUDED
#include <conio.h>
#include <windows.h>

#define Key_ESC 27
#define Key_LEFT 'a'
#define Key_RIGHT 'd'
#define Key_ENTER 13

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


namespace MuSoeun
{
	void gotoxy(int x, int y)
	{
		//x, y ��ǥ ����
		COORD pos = { x,y };

		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetCursorState()
	{

	}


	class MGameLoop
	{
	public:
		MGameLoop() {}
		~MGameLoop() {}

		bool isGameRunning = false;

		void Initialize()
		{
			//SetCursorState(false);
			std::cout << ANSI_COLOR_RESET "���� �ʱ�ȭ��" << std::endl;
			isGameRunning = true;
		}

		void Release()
		{
			std::cout << ANSI_COLOR_RESET "���� ����" << std::endl;
			isGameRunning = false;
		}

		void Update()
		{
			std::cout << ANSI_COLOR_RESET "���� Ű�Է� ���" << std::endl;
			if (_kbhit())
			{
				KeyEvent(_getch());
			}

			

		}

		void Rander()
		{
			std::cout << "���� ȭ�� �׸���" << std::endl;

		}

		void KeyEvent(char KeyInput)
		{
			switch (KeyInput)
			{
				/*
				�ѹ� esc ������ �Ͻ������� �ǰ�
				�����⸦ �����ϸ� ��������
				*/
			case Key_ESC:
				isGameRunning = false;
				break;
			case Key_LEFT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_RED"���� ����          " << std::endl;
				break;
			case Key_RIGHT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_BLUE"������ ����         " << std::endl;
				break;
			case Key_ENTER:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_YELLOW"����             " << std::endl;
				break;
			default:
				isGameRunning = true;
				break;
			}
		}

		void Run()
			{
				gotoxy(2, 9);
				Initialize();
				while (isGameRunning)
				{
					gotoxy(2, 10);
					Update();
					gotoxy(2, 11);
					Rander();
				}
				Release();
			}

	};
}