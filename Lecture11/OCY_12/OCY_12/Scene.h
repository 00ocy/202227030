#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include "Words.h"
#include <vector>
using namespace std;

namespace OCY_12
{
	class Scene
	{
	private:
		vector<string> screenBuf;
		std::vector<Word*> Words;
		int width;
		int height;
	public:
		Scene() {
			SetCursorState(false);
			width = 80; // 게임 창의 가로 크기
			height = 24; // 게임 창의 세로 크기
			screenBuf.resize(height, string(width, ' '));
			DrawBorder();
		}

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

		void DrawString(string s)
		{
			cout << s;
		}

		void Clear()
		{
			system("cls");
		}

		void DrawBorder()
		{
			for (int i = 0; i < width; i++) {
				screenBuf[0][i] = '#'; // 윗쪽 테두리
				screenBuf[height - 1][i] = '#'; // 아랫쪽 테두리
			}
			for (int i = 1; i < height - 1; i++) {
				screenBuf[i][0] = '#'; // 왼쪽 테두리
				screenBuf[i][width - 1] = '#'; // 오른쪽 테두리
			}
		}

		void DrawScreen()
		{
			// Words 벡터의 word들을 screenBuf에 넣어줌
			for (int i = 0; i < Words.size(); i++) {
				Word* word = Words[0];
				for (int j = 0; j < word->word.size(); j++) {
					int posX = word->x + j;
					int posY = word->y;
					if (posX >= 0 && posX < width && posY >= 0 && posY < height) {
						screenBuf[posY][posX] = word->word[j];
					}
				}
			}

			// screenBuf의 내용을 출력
			for (const auto& row : screenBuf) {
				cout << row << endl;
			}
		}
		
		void abc()
		{
			

			bool pKeyPressed = false; // 'P' 키가 눌렸는지 여부를 저장하는 변수
			bool mKeyPressed = false; // 'M' 키가 눌렸는지 여부를 저장하는 변수

			 
				if (!pKeyPressed && (GetAsyncKeyState('P') & 0x8000)) {
					pKeyPressed = true;
					Word* word = new Word(10,10,"과제");
					Words.push_back(word);
					std::cout << Words[0]->word << std::endl;
				}
				else if (!(GetAsyncKeyState('P') & 0x8000)) {
					pKeyPressed = false;
				}

				if (!mKeyPressed && (GetAsyncKeyState('M') & 0x8000)) {
					mKeyPressed = true;
					if (!Words.empty()) {
						Word* word = Words.back();
						Words.pop_back();
						delete word;
						std::cout << "Word 객체 제거됨" << std::endl;
					}
				}
				else if (!(GetAsyncKeyState('M') & 0x8000)) {
					mKeyPressed = false;
				}
			// 동적으로 할당된 Word 객체들 해제
			//for (Word* word : Words) {
			//	delete word;
			//}

		}
		void Draw()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			Clear(); // 화면 지우기
			DrawScreen(); // ScreenBuffer를 화면에 그리기

			//for (Word* word : Words)
			//{
			//	word->Render(); // Active한 Object의 Render 호출
			//}
			
		}
	};

}