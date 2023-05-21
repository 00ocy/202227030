#include <stdio.h>
#include "screen.h"
#include "Scene.h"
int main()
{
	/*  width : 30    height : 10    가로 여백 : 2    세로여백 :1 */
	char screenBuf[35 * 12 + 1];
	int width = 24;
	int height = 7;
	int isGamePlaying = 1;

	char input[10];

	while (isGamePlaying)
	{
		drawBorder(screenBuf, width, height);

		setTitleToScreenBuffer(screenBuf, width, height); /* 이런식으로 짜주세용 */

		system("cls");
		printf("%s\ninput>", screenBuf);
		scanf_s("%s", input);

		
	}

	return 0;
}