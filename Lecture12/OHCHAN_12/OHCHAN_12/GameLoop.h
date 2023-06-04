#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H

#pragma once 
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Scene.h"

using namespace std;

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define KEY_ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

namespace OHCHAN_12
{
	Scene scene;
	std::vector<Object*> objects;
	
	static int selectedShape;  // ���õ� ������ ��Ÿ���� ���� (0: ���� �� ��, 1: ����1, 2: ����2, 3: ����3)
	static bool receiveCoordinates;  // x�� y ���� �Է¹��� �������� ��Ÿ���� ����
	static int x, y;  // �Է¹��� x�� y ���� �����ϴ� ����
	// ����
	enum Direction { UP, DOWN, LEFT, RIGHT };

	// ���� ����
	bool gameOver;
	int score;


	// ���� �̵� ����
	Direction dir;

	// ��� ����
	Snake snake(200 / 2, 100 / 2);


	// ������
	vector<vector<char>> gameBoard;

	
	
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
			 
			if (scene.gamestate == 0)
			{
				std::cout << "1.���׶�� 2.���� 3.�׸�" << std::endl;
				if (_kbhit()) { KeyEvent_Title(_getch()); }
			}
			if (scene.gamestate == 1)
			{
				Input();
				Logic();
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

		// �ʱ�ȭ
		void Setup() {
			gameOver = false;
			dir = RIGHT;
			score = 0;

			// ������ �ʱ�ȭ
			gameBoard.resize(scene.WIDTH, vector<char>(scene.HEIGHT, ' '));

			// ���� �ʱ� ��ġ
			snake = Snake(scene.WIDTH / 2, scene.HEIGHT / 2);

			// �ʱ� ���� ����
			for (int i = 0; i < scene.INITIAL_LENGTH - 1; i++) {
				Snake tailSegment(snake.getX() - (i + 1), snake.getY());
				scene.tail.push_back(tailSegment);
			}
		}

		void Render()
		{
			/*for (Object* object : objects)
			{
				scene.Addbuf(object->GetX(), object->GetY(), object->GetShape());
			}*/
			scene.SceneRender();
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
	
		void KeyEvent_Title(char KeyInput)
		{
			
			switch (KeyInput)
			{
			case 49:

				scene.gamestate = 1;
				Setup();
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


	// �Է� ó��
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

	// ���� ���� ������Ʈ
	void Logic() {
		// ���� ��ġ ������Ʈ
		Snake prevTail = scene.tail[scene.tail.size() - 1];
		for (int i = scene.tail.size() - 1; i > 0; i--) {
			scene.tail[i] = scene.tail[i - 1];
		}
		scene.tail[0] = snake;

		// ���� �̵�
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

		// ���� �ε������� üũ
		if (snake.getX() < 0 || snake.getX() >= scene.WIDTH || snake.getY() < 0 || snake.getY() >= scene.HEIGHT)
			gameOver = true;

		// �ڱ� �ڽſ��� �ε������� üũ
		for (int i = 0; i < scene.tail.size(); i++) {
			if (snake.getX() == scene.tail[i].getX() && snake.getY() == scene.tail[i].getY())
				gameOver = true;
		}
	}






	};
}
#endif //HEADER_FILE_NAME_H