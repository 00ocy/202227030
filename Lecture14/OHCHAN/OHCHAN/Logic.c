#include "Logic.h"

// 게임 로직 업데이트
void mainMenu_Logic()
{
    // 메인 메뉴
    if (gameState == 0 || gameState == 3)
    {
        //입력받은 키보드값 화면 업데이트
        switch (selectMenu) {
        case 1:
            selectMenu = 1;
            break;
        case 2:
            selectMenu = 2;
            break;
        case 3:
            selectMenu = 3;
            break;
        case 4:
            selectMenu = 4;
            break;
        default:
            break;
        }
        if (mode == 0) { speed = 100; }
        if (mode == 1) { speed = 50; }
        if (mode == 2) { speed = 200; }
        if (selectMenu < 0) selectMenu = 4;
        if (selectMenu == 5) selectMenu = 1;
    }
    if (gameState == 0)
    {
        WriteToBuffer(27, 7, "_______________");
        WriteToBuffer(26, 4, "◎Ο과제 먹는 뱀οo");
        WriteToBuffer(30, 9, "게임 시작");
        WriteToBuffer(30, 11, "게임 설명");
        WriteToBuffer(30, 13, "게임 종료");
        WriteToBuffer(33, 15, "옵션");
        WriteToBuffer(27, 17, "---------------");
        WriteToBuffer(2, 17, "W/S : 위/아래");
        WriteToBuffer(2, 18, "Ent : 선택");



        WriteToBuffer(28, 9, "  ");
        WriteToBuffer(28, 11, "  ");
        WriteToBuffer(28, 13, "  ");
        WriteToBuffer(30, 15, "  ");
        if (selectMenu == 1)WriteToBuffer(28, 9, "▶");
        if (selectMenu == 2)WriteToBuffer(28, 11, "▶");
        if (selectMenu == 3)WriteToBuffer(28, 13, "▶");
        if (selectMenu == 4)WriteToBuffer(30, 15, "▶");
    }
}

void gamePlay_Logic()
{
    // 게임 플레이
    memset(ScreenBuffer, '\0', sizeof(ScreenBuffer));

    score();

    // 꼬리 위치 업데이트
    Snake prevTail = tail[tailLength];

    for (int i = tailLength - 1; i > 0; i--) {
        tail[i] = tail[i - 1];
    }
    tail[0] = snake;

    // 뱀의 이동
    switch (dir) {
    case UP:
        snake.y = snake.y - 1;
        break;
    case DOWN:
        snake.y = snake.y + 1;
        break;
    case LEFT:
        snake.x = snake.x - 1;
        break;
    case RIGHT:
        snake.x = snake.x + 1;
        break;
    }

    // 화면 버퍼 초기화
    for (int i = 0; i < VIEW_WIDTH * VIEW_HEIGHT + VIEW_HEIGHT; i++)
    {
        ScreenBuffer[i] = ' ';
    }

    // 게임판 그리기
    for (int i = 0; i < VIEW_HEIGHT; i++)
    {
        for (int j = 0; j < VIEW_WIDTH; j++)
        {
            int mapX = snake.x - (VIEW_WIDTH / 2) + j;
            int mapY = snake.y - (VIEW_HEIGHT / 2) + i;

            // 테두리인 경우
            if (mapX < 0 || mapX >= WIDTH || mapY < 0 || mapY >= HEIGHT)
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = '~'; // 게임 판 바깥
            }
            // 게임판 내부
            else if (i == 0 || i == VIEW_HEIGHT - 1 || j == 0 || j == VIEW_WIDTH - 1)
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = '*'; // 시야의 테두리
            }
            // 과제인 경우
            else if (isAssignmentInArray(mapX, mapY, assignment, NUM_ASSIGNMENT))
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = assignment->shape; //뱀 모양
            }

            // 벽인 경우 
            else if (isWallInArray(mapX, mapY, walls, NUM_WALLS))
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = walls->shape; //벽 모양
            }

            else
            {
                // 뱀의 위치
                if (mapX == snake.x && mapY == snake.y)
                {
                    ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = snakeHead;
                }

                // 꼬리의 위치
                else
                {
                    int isTail = 0;
                    int isBody = 0;

                    for (int k = 0; k < tailLength; k++)
                    {
                        if (tail[k].x == mapX && tail[k].y == mapY)
                        {

                            if (k == 0)
                            {
                                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = 'o';  // 뱀의 몸통
                            }

                            else
                            {
                                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = 'o';  // 뱀의 꼬리
                                isBody = 1;
                            }

                            isTail = 1;
                            break;
                        }
                    }

                    if (!isTail && !isBody) {
                        ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = ' ';
                    }
                }
            }
        }


        ScreenBuffer[i * (VIEW_WIDTH + 1) + VIEW_WIDTH] = '\n';

        WriteToBuffer(106, 16, "\n\n과제     /      ");
        WriteToBuffer(113, 16, strAssignment);
        WriteToBuffer(120, 16, strProgress);

        WriteToBuffer(123, 16, "\n\n과제 등급  A :    B :    C : ");
        WriteToBuffer(138, 16, strA);
        WriteToBuffer(145, 16, strB);
        WriteToBuffer(152, 16, strC);
    }

    // 학점 충돌 감지 씬 C에도 있음
    for (int i = 0; i < NUM_ASSIGNMENT; i++)
    {
        if (snake.x == assignment[i].x && snake.y == assignment[i].y)
        {
            // 충돌한 과일을 빈 값으로 초기화하여 제거
            assignment[i].x = -1;
            assignment[i].y = -1;
            Progress++;

            // 뱀의 길이를 증가시킴
            tailLength++;
            if (assignment->shape == 'A')
            {
                A++;
                Hakjum += 4;
            }
            else if (assignment->shape == 'B')
            {
                B++;
                Hakjum += 3;
            }
            else if (assignment->shape == 'C')
            {
                C++;
                Hakjum += 2;
            }
            break;
        }
    }

    /* 벽 충돌 감지*/ //씬 c에도 있음        
    for (int i = 0; i < NUM_WALLS; i++)
    {
        if (snake.x == walls[i].x && snake.y == walls[i].y)
        {
            PlayEnd();
            break;
        }
    }

    // 외곽 벽에 부딪혔는지 체크
    if (snake.x < 0 || snake.x >= WIDTH || snake.y < 0 || snake.y >= HEIGHT)
    {
        PlayEnd();
    }

    // 자기 자신에게 부딪혔는지 체크
    for (int i = 0; i < tailLength; i++) {
        if (snake.x == tail[i].x && snake.y == tail[i].y)
        {
            PlayEnd();
            break;
        }
    }

}
void gameDescription_Logic()
{
    WriteToBuffer(26, 4, "◎Ο과제 먹는 뱀οo");
    WriteToBuffer(18, 7, "불쌍한 뱀은 마귀같은 과제를 받았다....");
    WriteToBuffer(13, 9, "??? : _(▤_▤)/ 이거 못하면 당신들은 죽어야 돼ㅋㅋ");
    WriteToBuffer(18, 12, "ㅎㅎ;;; 뱀을 도와 과제를 해치우자");
    WriteToBuffer(5, 16, "1. wasd로 뱀을 조작하여 과제(A/B/C)를 먹어치워야 한다.");
    WriteToBuffer(5, 17, "2. 타이밍에 맞춰 높은 등급의 과제를 먹는것이 Point");
    WriteToBuffer(5, 18, "3. 과제를 할 수록 몸이 늘어지니 부딪히지 말것!");
    WriteToBuffer(55, 2, "X : 뒤로가기");
}

void option_Logic() {

        
    if (snakeHead > 'Z') {snakeHead = 'A';}        // 뱀 머리 제한
       
        strHead[0] = snakeHead;                    // 뱀 머리를 문자열로 (화면에 출력하려고)


        WriteToBuffer(27, 7, "_______________");
        WriteToBuffer(26, 4, "◎Ο과제 먹는 뱀οo");
        WriteToBuffer(30, 10, "난이도");


        if (mode == 0)
        {
            WriteToBuffer(37, 10, "중");
            speed = 120;
        }
        if (mode == 1)
        {
            WriteToBuffer(37, 10, "상");
            speed = 70;
        }
        if (mode == 2)
        {
            WriteToBuffer(37, 10, "하");
            speed = 200;
        }

        WriteToBuffer(30, 13, "뱀 머리");
        WriteToBuffer(38, 13, strHead);
        WriteToBuffer(27, 16, "---------------");

        WriteToBuffer(27, 10, "  ");
        WriteToBuffer(27, 13, "  ");

        if (selectMenu == 1)WriteToBuffer(27, 10, "▶");
        if (selectMenu == 2)WriteToBuffer(27, 13, "▶");
        WriteToBuffer(55, 2, "X : 뒤로가기");
        WriteToBuffer(2, 17, "W/S : 위/아래");
        WriteToBuffer(2, 18, "Ent : 선택");

    

}
void playerDeath_Logic()
{

    WriteToBuffer(17, 7, "___________________________________");
    if (jumsu < 1)
    {
        WriteToBuffer(20, 5, "평점이 1점도 안 나오면 ㅋㅋ.....");
        WriteToBuffer(20, 13, "F학점F학점F학점F학점F학점F학점");
        WriteToBuffer(20, 14, "F학점F학점F학점F학점F학점F학점");
    }
    else if (jumsu < 2)
    {
        WriteToBuffer(18, 5, "그래도 학점은 나왔네.. F는 면했다");
        WriteToBuffer(20, 13, "D학점D학점D학점D학점D학점D학점");
        WriteToBuffer(20, 14, "D학점D학점D학점D학점D학점D학점");
    }
    else if (jumsu < 3)
    {
        WriteToBuffer(18, 5, "많이 아쉽구나, 더 분발하도록 하렴");
        WriteToBuffer(20, 13, "C학점C학점C학점C학점C학점C학점");
        WriteToBuffer(20, 14, "C학점C학점C학점C학점C학점C학점");
    }
    else if (jumsu < 3.5)
    {
        WriteToBuffer(18, 5, "흠...뭔가 잘했는데 조금 아쉬운걸?");
        WriteToBuffer(20, 13, "B학점B학점B학점B학점B학점B학점");
        WriteToBuffer(20, 14, "B학점B학점B학점B학점B학점B학점");
    }
    else if (jumsu < 3.9)
    {
        WriteToBuffer(18, 5, "엄청 열심히 했구나, 아주 잘했어^^");
        WriteToBuffer(20, 13, "A학점A학점A학점A학점A학점A학점");
        WriteToBuffer(20, 14, "A학점A학점A학점A학점A학점A학점");
    }
    else if (jumsu == 4)
    {
        WriteToBuffer(18, 5, "....자네 대학원생 해볼 생각 없나?");
        WriteToBuffer(16, 13, "이걸 성공해?이걸 성공해?이걸 성공해?");
        WriteToBuffer(16, 14, "이걸 성공해?이걸 성공해?이걸 성공해?");
    }
    WriteToBuffer(18, 9, "제출한 과제      /    ");
    WriteToBuffer(31, 9, strAssignment);
    WriteToBuffer(39, 9, strProgress);
    WriteToBuffer(25, 10, "등급  A :    B :    C : ");
    WriteToBuffer(35, 10, strA);
    WriteToBuffer(42, 10, strB);
    WriteToBuffer(49, 10, strC);


    WriteToBuffer(25, 11, "평점");
    WriteToBuffer(31, 11, strJumsu);

    WriteToBuffer(17, 16, "-----------------------------------");

    WriteToBuffer(18, 18, "*** X 키를 눌러서 메인 메뉴로 ***");

}
/////////////////////////////////////////////////////


/* 랜덤 위치에 벽 생성하기*/
void generateWalls()
{
    walls = (struct Wall*)malloc(NUM_WALLS * sizeof(struct Wall));


    if (walls == NULL)
    {
        // 동적 메모리 할당 실패
        printf("벽에 대한 메모리 할당에 실패했습니다.\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_WALLS; i++) {
        int x, y;

        //겹쳤는지 확인
        bool overlap;
        do {
            x = rand() % (WIDTH - 2) + 1;
            y = rand() % (HEIGHT - 2) + 1;
            overlap = false;

            for (int j = 0; j < i; j++)
            {
                if (walls[j].x == x && walls[j].y == y)
                {
                    overlap = true;
                    break;
                }
            }
        } while (overlap || (abs(snake.x - x) < 15 && abs(snake.y - y) < 8)); // Check if wall is within 10x10 range of snake

        walls[i].x = x;
        walls[i].y = y;
        walls[i].shape = 'F';
    }
}


/* 랜덤 위치에 과제 생성하기*/
void generateAssignments()
{
    assignment = (struct Assignment*)malloc(NUM_ASSIGNMENT * sizeof(struct Assignment));

    srand(time(NULL));

    for (int i = 0; i < NUM_ASSIGNMENT; i++)
    {
        int x, y;

        //겹쳤는지 확인
        bool overlap;
        do {
            x = rand() % (WIDTH - 2) + 1;
            y = rand() % (HEIGHT - 2) + 1;
            overlap = false;

            for (int j = 0; j < i; j++) {
                if (assignment[j].x == x && assignment[j].y == y) {
                    overlap = true;
                    break;
                }
            }

            for (int j = 0; j < NUM_WALLS; j++) {
                if (walls[j].x == x && walls[j].y == y) {
                    overlap = true;
                    break;
                }
            }

        } while (overlap || (abs(snake.x - x) < 15 && abs(snake.y - y) < 8)); // Check if fruit is within 10x10 range of snake

        assignment[i].x = x;
        assignment[i].y = y;
        assignment[i].shape = 'A';
    }
}

/* 플레이 화면에서 학점 그릴때 체크하려고*/
bool isAssignmentInArray(int x, int y, struct Assignment* fruits, int numFruitss)
{
    for (int i = 0; i < numFruitss; i++)
    {
        if (fruits[i].x == x && fruits[i].y == y)
        {
            return true;
        }
    }

    return false;
}
/* 플레이 화면에서 벽 그릴때 체크하려고*/
bool isWallInArray(int x, int y, struct Wall* walls, int numWalls)
{
    for (int i = 0; i < numWalls; i++)
    {
        if (walls[i].x == x && walls[i].y == y)
        {
            return true;
        }
    }

    return false;
}

void PlayStart()
{
    dir = RIGHT;
    A = 0;
    B = 0;
    C = 0;
    Progress = 0;
    Hakjum = 0;
    setScreenSize(70, 20);
    AssignmentNum = NUM_ASSIGNMENT;
    snake.x = WIDTH / 2;
    snake.y = HEIGHT / 2;
    gameState = 0;
    play = 1;
    system("cls");
    ClearBuffer();

    // 벽, 과일 생성
    generateWalls();
    generateAssignments();

    // 초기 꼬리 생성
    tailLength = 5; // 뱀의 길이 초기화
    for (int i = 0; i < tailLength; i++) {
        tail[i].x = snake.x - (i + 1);
        tail[i].y = snake.y;
    }


    srand(time(NULL));

    // 쓰레드 생성
    thread = CreateThread(NULL, 0, updateAssignmentShapes, NULL, 0, &threadId);
    if (thread == NULL) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

}

void PlayEnd()
{
    printf("  으아아아아아앙 아프(F) 다!!");
    Sleep(2500);
    system("cls");
    ClearBuffer();
    gameState = 4;
    play = 0;
    CloseHandle(thread);

}

/* 커서위치 */
void setCursorPos(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

DWORD WINAPI updateAssignmentShapes()
{
    int currentIndex = 0;

    while (play)
    {
        for (int i = 0; i < NUM_ASSIGNMENT; i++)
        {
            assignment[i].shape = 'A' + currentIndex % 3;
            currentIndex++;
        }

        Sleep(1000); // 1초 대기
    }
    return 0;
}