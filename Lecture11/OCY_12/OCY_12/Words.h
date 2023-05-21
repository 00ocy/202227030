#include "Object.h"

using namespace std;

namespace OCY_12
{
	class Word : public Object
	{

	public:

		short x, y;
		std::string word;

		Word()
			: x(5), y(5), word("과제에") // 멤버 초기화 목록을 사용하여 초기화
		{
		}

		Word(short a, short b, std::string word)
			: x(b), y(a), word(word) // 멤버 초기화 목록을 사용하여 초기화
		{
			x = 10;
			y = 15;
			word = "과제에";
		}
		~Word()
		{

		}
		// 다른 멤버 함수들
		void Render()
		{
			MoveCursor(x, y);
			DrawString(word);
		}
		void MoveCursor(short x, short y)
		{
			COORD position = { x , y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		}
		void DrawString(string s)
		{
			cout << s;
		}

	};

	class FakeWord : public Object
	{
	public:
		int x, y;
		std::string fakeword;
		FakeWord()
		{
			fakeword = "과자";
			x = 20;
			y = 7;
		}
		~FakeWord()
		{

		}

		void isKeyPressed()
		{
			y = 5;
		}

		void isKeyUnpressed()
		{
			y = 7;
		}

	};
}