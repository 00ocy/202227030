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
	
	static int selectedShape;  // 선택된 도형을 나타내는 변수 (0: 선택 안 됨, 1: 도형1, 2: 도형2, 3: 도형3)
	static bool receiveCoordinates;  // x와 y 값을 입력받을 상태인지 나타내는 변수
	static int x, y;  // 입력받은 x와 y 값을 저장하는 변수
	// 방향
	enum Direction { UP, DOWN, LEFT, RIGHT };

	// 게임 상태
	bool gameOver;
	int score;


	// 뱀의 이동 방향
	Direction dir;

	// 뱀과 과일
	Snake snake(200 / 2, 100 / 2);


	// 게임판
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

		bool isGameRunning = false;    //게임실행 체크
		bool exitselect = false;       //ESC눌렀을때 체크
		bool OnOff = true;             //끄냐 마냐 체크
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
			
			std::cout << ANSI_COLOR_RESET"종료하시겠습니까?" << std::endl;
			std::cout << "               " << std::endl;
			std::cout << ANSI_COLOR_YELLOW"     [ 예 ]";
			std::cout << ANSI_COLOR_RESET"   [ 아니오 ]" << std::endl;

			while (exitselect)
			{
				if (_kbhit()) { KeyEvent2(_getch()); }
			}
		}

		void Update()
		{
			//MoveCursor(3, 16);
			//std::cout << ANSI_COLOR_RESET"게임 키입력 대기" << std::endl;
			 
			if (scene.gamestate == 0)
			{
				std::cout << "1.동그라미 2.세모 3.네모" << std::endl;
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
				std::cout << "Y 좌표 입력 : " ;
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
			//나중에 여기에 UISTATE 넣어야 할듯
			if (_kbhit()) { KeyEvent(_getch()); }
			

		}

		// 초기화
		void Setup() {
			gameOver = false;
			dir = RIGHT;
			score = 0;

			// 게임판 초기화
			gameBoard.resize(scene.WIDTH, vector<char>(scene.HEIGHT, ' '));

			// 뱀의 초기 위치
			snake = Snake(scene.WIDTH / 2, scene.HEIGHT / 2);

			// 초기 꼬리 생성
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
			//	//std::cout << ANSI_COLOR_RED"왼쪽 눌림  " << std::endl;
			//	break;

			//case KEY_RIGHT:
			//	MoveCursor(5, 5);
			//	std::cout << ANSI_COLOR_GREEN"오른쪽 눌림" << std::endl;
			//	break;

			//case KEY_ENTER:
			//	MoveCursor(5, 5);
			//	std::cout << ANSI_COLOR_BLUE"엔터 눌림  " << std::endl;
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
				std::cout << ANSI_COLOR_YELLOW"[ 예 ]";
				std::cout << ANSI_COLOR_RESET"   [ 아니오 ]" << std::endl;
				OnOff = true;
				break;

			case KEY_RIGHT:
				MoveCursor(5, 9);
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
				else { isGameRunning = true; Run(); }
				break;

			default:
				isGameRunning = true;
				break;
			}
		}


	// 입력 처리
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

	// 게임 로직 업데이트
	void Logic() {
		// 꼬리 위치 업데이트
		Snake prevTail = scene.tail[scene.tail.size() - 1];
		for (int i = scene.tail.size() - 1; i > 0; i--) {
			scene.tail[i] = scene.tail[i - 1];
		}
		scene.tail[0] = snake;

		// 뱀의 이동
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

		// 벽에 부딪혔는지 체크
		if (snake.getX() < 0 || snake.getX() >= scene.WIDTH || snake.getY() < 0 || snake.getY() >= scene.HEIGHT)
			gameOver = true;

		// 자기 자신에게 부딪혔는지 체크
		for (int i = 0; i < scene.tail.size(); i++) {
			if (snake.getX() == scene.tail[i].getX() && snake.getY() == scene.tail[i].getY())
				gameOver = true;
		}
	}






	};
}
#endif //HEADER_FILE_NAME_H