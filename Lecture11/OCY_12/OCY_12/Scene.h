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
			width = 80; // ���� â�� ���� ũ��
			height = 24; // ���� â�� ���� ũ��
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
				screenBuf[0][i] = '#'; // ���� �׵θ�
				screenBuf[height - 1][i] = '#'; // �Ʒ��� �׵θ�
			}
			for (int i = 1; i < height - 1; i++) {
				screenBuf[i][0] = '#'; // ���� �׵θ�
				screenBuf[i][width - 1] = '#'; // ������ �׵θ�
			}
		}

		void DrawScreen()
		{
			// Words ������ word���� screenBuf�� �־���
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

			// screenBuf�� ������ ���
			for (const auto& row : screenBuf) {
				cout << row << endl;
			}
		}
		
		void abc()
		{
			

			bool pKeyPressed = false; // 'P' Ű�� ���ȴ��� ���θ� �����ϴ� ����
			bool mKeyPressed = false; // 'M' Ű�� ���ȴ��� ���θ� �����ϴ� ����

			 
				if (!pKeyPressed && (GetAsyncKeyState('P') & 0x8000)) {
					pKeyPressed = true;
					Word* word = new Word(10,10,"����");
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
						std::cout << "Word ��ü ���ŵ�" << std::endl;
					}
				}
				else if (!(GetAsyncKeyState('M') & 0x8000)) {
					mKeyPressed = false;
				}
			// �������� �Ҵ�� Word ��ü�� ����
			//for (Word* word : Words) {
			//	delete word;
			//}

		}
		void Draw()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			Clear(); // ȭ�� �����
			DrawScreen(); // ScreenBuffer�� ȭ�鿡 �׸���

			//for (Word* word : Words)
			//{
			//	word->Render(); // Active�� Object�� Render ȣ��
			//}
			
		}
	};

}