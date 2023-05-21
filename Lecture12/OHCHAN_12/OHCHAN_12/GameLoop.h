#pragma once 
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Scene.h"


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

namespace OHCHAN_12
{
	Scene screenBuf(82,24);
	std::vector<Object*> objects;
	
	static int selectedShape;  // ���õ� ������ ��Ÿ���� ���� (0: ���� �� ��, 1: ����1, 2: ����2, 3: ����3)
	static bool receiveCoordinates;  // x�� y ���� �Է¹��� �������� ��Ÿ���� ����
	static int x, y;  // �Է¹��� x�� y ���� �����ϴ� ����

	
	
	void MoveCursor(short x, short y)
	{
		COORD position = { x , y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

	void SetCursorState(bool visible)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = visible;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}


	class GameLoop
	{
	public:
		GameLoop() { SetCursorState(false); }
		~GameLoop() {}

		bool isGameRunning = false;    //���ӽ��� üũ
		bool exitselect = false;       //ESC�������� üũ
		bool OnOff = true;             //���� ���� üũ
		int uistate = 0;

		void Initialize()
		{
			SetCursorState(false);

			isGameRunning = true;
			exitselect = true;
		}

		void Release()
		{
			isGameRunning = false;
			system("cls");
			MoveCursor(5, 7);
			
			std::cout << ANSI_COLOR_RESET"�����Ͻðڽ��ϱ�?" << std::endl;
			std::cout << "               " << std::endl;
			std::cout << ANSI_COLOR_YELLOW"     [ �� ]";
			std::cout << ANSI_COLOR_RESET"   [ �ƴϿ� ]" << std::endl;

			while (exitselect)
			{
				if (_kbhit()) { KeyEvent2(_getch()); }
			}
		}

		void Update()
		{
			//MoveCursor(3, 16);
			//std::cout << ANSI_COLOR_RESET"���� Ű�Է� ���" << std::endl;
			 
			if (uistate == 0)
			{
				std::cout << "1.���׶�� 2.���� 3.�׸�" << std::endl;
				if (_kbhit()) { KeyEvent_Shape(_getch()); }
			}
			if (uistate == 1)
			{
				std::string xString;
				std::cout << "X ��ǥ �Է� : " ;
				std::getline(std::cin, xString);	
				x = std::stoi(xString);
				uistate = 2;
			}
			if (uistate == 2)
			{
				std::string yString;
				std::cout << "Y ��ǥ �Է� : " ;
				std::getline(std::cin, yString);
				y = std::stoi(yString);
				if (selectedShape == 1)
				{
					objects.push_back(new Circle(x, y));
				}
				else if(selectedShape == 2)
				{
					objects.push_back(new Triangle(x, y));
				}
				else if (selectedShape == 3)
				{
					objects.push_back(new Square(x, y));
				}
				uistate = 0;
			}
			//���߿� ���⿡ UISTATE �־�� �ҵ�
			if (_kbhit()) { KeyEvent(_getch()); }
			

		}

		void Render()
		{
			for (Object* object : objects)
			{
				screenBuf.Addbuf(object->GetX(), object->GetY(), object->GetShape());
			}
			screenBuf.SceneRender();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			system("cls");
			
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
	
		void KeyEvent_Shape(char KeyInput)
		{
			
			switch (KeyInput)
			{
			case 49:
				selectedShape = 1;
				uistate = 1;
				break;
			case 50:
				selectedShape = 2;
				uistate = 1;
				break;
			case 51:
				selectedShape = 3;
				uistate = 1;
				break;
			default:

				isGameRunning = true;
				break;
			}
		}
		void KeyEvent(char KeyInput)
		{

			switch (KeyInput)
			{
			case KEY_ESC:
				MoveCursor(5, 5);
				Release();
				break;

			//case KEY_LEFT:
			//	
			//	objects.push_back(new Object(x,y));
			//	//MoveCursor(5, 5);
			//	//std::cout << ANSI_COLOR_RED"���� ����  " << std::endl;
			//	break;

			//case KEY_RIGHT:
			//	MoveCursor(5, 5);
			//	std::cout << ANSI_COLOR_GREEN"������ ����" << std::endl;
			//	break;

			//case KEY_ENTER:
			//	MoveCursor(5, 5);
			//	std::cout << ANSI_COLOR_BLUE"���� ����  " << std::endl;
			//	break;

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
				MoveCursor(5, 9);
				std::cout << ANSI_COLOR_YELLOW"[ �� ]";
				std::cout << ANSI_COLOR_RESET"   [ �ƴϿ� ]" << std::endl;
				OnOff = true;
				break;

			case KEY_RIGHT:
				MoveCursor(5, 9);
				std::cout << ANSI_COLOR_RESET"[ �� ]";
				std::cout << ANSI_COLOR_YELLOW"   [ �ƴϿ� ]" << std::endl;
				OnOff = false;
				break;

			case KEY_ENTER:
				if (OnOff)
				{
					exitselect = false;
					isGameRunning = false;
				}
				else { isGameRunning = true; Run(); }
				break;

			default:
				isGameRunning = true;
				break;
			}
		}
	};
}