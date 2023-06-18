#include "Logic.h"

// ���� ���� ������Ʈ
void mainMenu_Logic()
{
    // ���� �޴�
    if (gameState == 0 || gameState == 3)
    {
        //�Է¹��� Ű���尪 ȭ�� ������Ʈ
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
        WriteToBuffer(26, 4, "�ݥϰ��� �Դ� ���o");
        WriteToBuffer(30, 9, "���� ����");
        WriteToBuffer(30, 11, "���� ����");
        WriteToBuffer(30, 13, "���� ����");
        WriteToBuffer(33, 15, "�ɼ�");
        WriteToBuffer(27, 17, "---------------");
        WriteToBuffer(2, 17, "W/S : ��/�Ʒ�");
        WriteToBuffer(2, 18, "Ent : ����");



        WriteToBuffer(28, 9, "  ");
        WriteToBuffer(28, 11, "  ");
        WriteToBuffer(28, 13, "  ");
        WriteToBuffer(30, 15, "  ");
        if (selectMenu == 1)WriteToBuffer(28, 9, "��");
        if (selectMenu == 2)WriteToBuffer(28, 11, "��");
        if (selectMenu == 3)WriteToBuffer(28, 13, "��");
        if (selectMenu == 4)WriteToBuffer(30, 15, "��");
    }
}

void gamePlay_Logic()
{
    // ���� �÷���
    memset(ScreenBuffer, '\0', sizeof(ScreenBuffer));

    score();

    // ���� ��ġ ������Ʈ
    Snake prevTail = tail[tailLength];

    for (int i = tailLength - 1; i > 0; i--) {
        tail[i] = tail[i - 1];
    }
    tail[0] = snake;

    // ���� �̵�
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

    // ȭ�� ���� �ʱ�ȭ
    for (int i = 0; i < VIEW_WIDTH * VIEW_HEIGHT + VIEW_HEIGHT; i++)
    {
        ScreenBuffer[i] = ' ';
    }

    // ������ �׸���
    for (int i = 0; i < VIEW_HEIGHT; i++)
    {
        for (int j = 0; j < VIEW_WIDTH; j++)
        {
            int mapX = snake.x - (VIEW_WIDTH / 2) + j;
            int mapY = snake.y - (VIEW_HEIGHT / 2) + i;

            // �׵θ��� ���
            if (mapX < 0 || mapX >= WIDTH || mapY < 0 || mapY >= HEIGHT)
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = '~'; // ���� �� �ٱ�
            }
            // ������ ����
            else if (i == 0 || i == VIEW_HEIGHT - 1 || j == 0 || j == VIEW_WIDTH - 1)
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = '*'; // �þ��� �׵θ�
            }
            // ������ ���
            else if (isAssignmentInArray(mapX, mapY, assignment, NUM_ASSIGNMENT))
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = assignment->shape; //�� ���
            }

            // ���� ��� 
            else if (isWallInArray(mapX, mapY, walls, NUM_WALLS))
            {
                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = walls->shape; //�� ���
            }

            else
            {
                // ���� ��ġ
                if (mapX == snake.x && mapY == snake.y)
                {
                    ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = snakeHead;
                }

                // ������ ��ġ
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
                                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = 'o';  // ���� ����
                            }

                            else
                            {
                                ScreenBuffer[i * (VIEW_WIDTH + 1) + j] = 'o';  // ���� ����
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

        WriteToBuffer(106, 16, "\n\n����     /      ");
        WriteToBuffer(113, 16, strAssignment);
        WriteToBuffer(120, 16, strProgress);

        WriteToBuffer(123, 16, "\n\n���� ���  A :    B :    C : ");
        WriteToBuffer(138, 16, strA);
        WriteToBuffer(145, 16, strB);
        WriteToBuffer(152, 16, strC);
    }

    // ���� �浹 ���� �� C���� ����
    for (int i = 0; i < NUM_ASSIGNMENT; i++)
    {
        if (snake.x == assignment[i].x && snake.y == assignment[i].y)
        {
            // �浹�� ������ �� ������ �ʱ�ȭ�Ͽ� ����
            assignment[i].x = -1;
            assignment[i].y = -1;
            Progress++;

            // ���� ���̸� ������Ŵ
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

    /* �� �浹 ����*/ //�� c���� ����        
    for (int i = 0; i < NUM_WALLS; i++)
    {
        if (snake.x == walls[i].x && snake.y == walls[i].y)
        {
            PlayEnd();
            break;
        }
    }

    // �ܰ� ���� �ε������� üũ
    if (snake.x < 0 || snake.x >= WIDTH || snake.y < 0 || snake.y >= HEIGHT)
    {
        PlayEnd();
    }

    // �ڱ� �ڽſ��� �ε������� üũ
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
    WriteToBuffer(26, 4, "�ݥϰ��� �Դ� ���o");
    WriteToBuffer(18, 7, "�ҽ��� ���� ���Ͱ��� ������ �޾Ҵ�....");
    WriteToBuffer(13, 9, "??? : _(��_��)/ �̰� ���ϸ� ��ŵ��� �׾�� �Ť���");
    WriteToBuffer(18, 12, "����;;; ���� ���� ������ ��ġ����");
    WriteToBuffer(5, 16, "1. wasd�� ���� �����Ͽ� ����(A/B/C)�� �Ծ�ġ���� �Ѵ�.");
    WriteToBuffer(5, 17, "2. Ÿ�ֿ̹� ���� ���� ����� ������ �Դ°��� Point");
    WriteToBuffer(5, 18, "3. ������ �� ���� ���� �þ����� �ε����� ����!");
    WriteToBuffer(55, 2, "X : �ڷΰ���");
}

void option_Logic() {

        
    if (snakeHead > 'Z') {snakeHead = 'A';}        // �� �Ӹ� ����
       
        strHead[0] = snakeHead;                    // �� �Ӹ��� ���ڿ��� (ȭ�鿡 ����Ϸ���)


        WriteToBuffer(27, 7, "_______________");
        WriteToBuffer(26, 4, "�ݥϰ��� �Դ� ���o");
        WriteToBuffer(30, 10, "���̵�");


        if (mode == 0)
        {
            WriteToBuffer(37, 10, "��");
            speed = 120;
        }
        if (mode == 1)
        {
            WriteToBuffer(37, 10, "��");
            speed = 70;
        }
        if (mode == 2)
        {
            WriteToBuffer(37, 10, "��");
            speed = 200;
        }

        WriteToBuffer(30, 13, "�� �Ӹ�");
        WriteToBuffer(38, 13, strHead);
        WriteToBuffer(27, 16, "---------------");

        WriteToBuffer(27, 10, "  ");
        WriteToBuffer(27, 13, "  ");

        if (selectMenu == 1)WriteToBuffer(27, 10, "��");
        if (selectMenu == 2)WriteToBuffer(27, 13, "��");
        WriteToBuffer(55, 2, "X : �ڷΰ���");
        WriteToBuffer(2, 17, "W/S : ��/�Ʒ�");
        WriteToBuffer(2, 18, "Ent : ����");

    

}
void playerDeath_Logic()
{

    WriteToBuffer(17, 7, "___________________________________");
    if (jumsu < 1)
    {
        WriteToBuffer(20, 5, "������ 1���� �� ������ ����.....");
        WriteToBuffer(20, 13, "F����F����F����F����F����F����");
        WriteToBuffer(20, 14, "F����F����F����F����F����F����");
    }
    else if (jumsu < 2)
    {
        WriteToBuffer(18, 5, "�׷��� ������ ���Գ�.. F�� ���ߴ�");
        WriteToBuffer(20, 13, "D����D����D����D����D����D����");
        WriteToBuffer(20, 14, "D����D����D����D����D����D����");
    }
    else if (jumsu < 3)
    {
        WriteToBuffer(18, 5, "���� �ƽ�����, �� �й��ϵ��� �Ϸ�");
        WriteToBuffer(20, 13, "C����C����C����C����C����C����");
        WriteToBuffer(20, 14, "C����C����C����C����C����C����");
    }
    else if (jumsu < 3.5)
    {
        WriteToBuffer(18, 5, "��...���� ���ߴµ� ���� �ƽ����?");
        WriteToBuffer(20, 13, "B����B����B����B����B����B����");
        WriteToBuffer(20, 14, "B����B����B����B����B����B����");
    }
    else if (jumsu < 3.9)
    {
        WriteToBuffer(18, 5, "��û ������ �߱���, ���� ���߾�^^");
        WriteToBuffer(20, 13, "A����A����A����A����A����A����");
        WriteToBuffer(20, 14, "A����A����A����A����A����A����");
    }
    else if (jumsu == 4)
    {
        WriteToBuffer(18, 5, "....�ڳ� ���п��� �غ� ���� ����?");
        WriteToBuffer(16, 13, "�̰� ������?�̰� ������?�̰� ������?");
        WriteToBuffer(16, 14, "�̰� ������?�̰� ������?�̰� ������?");
    }
    WriteToBuffer(18, 9, "������ ����      /    ");
    WriteToBuffer(31, 9, strAssignment);
    WriteToBuffer(39, 9, strProgress);
    WriteToBuffer(25, 10, "���  A :    B :    C : ");
    WriteToBuffer(35, 10, strA);
    WriteToBuffer(42, 10, strB);
    WriteToBuffer(49, 10, strC);


    WriteToBuffer(25, 11, "����");
    WriteToBuffer(31, 11, strJumsu);

    WriteToBuffer(17, 16, "-----------------------------------");

    WriteToBuffer(18, 18, "*** X Ű�� ������ ���� �޴��� ***");

}
/////////////////////////////////////////////////////


/* ���� ��ġ�� �� �����ϱ�*/
void generateWalls()
{
    walls = (struct Wall*)malloc(NUM_WALLS * sizeof(struct Wall));


    if (walls == NULL)
    {
        // ���� �޸� �Ҵ� ����
        printf("���� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_WALLS; i++) {
        int x, y;

        //���ƴ��� Ȯ��
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


/* ���� ��ġ�� ���� �����ϱ�*/
void generateAssignments()
{
    assignment = (struct Assignment*)malloc(NUM_ASSIGNMENT * sizeof(struct Assignment));

    srand(time(NULL));

    for (int i = 0; i < NUM_ASSIGNMENT; i++)
    {
        int x, y;

        //���ƴ��� Ȯ��
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

/* �÷��� ȭ�鿡�� ���� �׸��� üũ�Ϸ���*/
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
/* �÷��� ȭ�鿡�� �� �׸��� üũ�Ϸ���*/
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

    // ��, ���� ����
    generateWalls();
    generateAssignments();

    // �ʱ� ���� ����
    tailLength = 5; // ���� ���� �ʱ�ȭ
    for (int i = 0; i < tailLength; i++) {
        tail[i].x = snake.x - (i + 1);
        tail[i].y = snake.y;
    }


    srand(time(NULL));

    // ������ ����
    thread = CreateThread(NULL, 0, updateAssignmentShapes, NULL, 0, &threadId);
    if (thread == NULL) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

}

void PlayEnd()
{
    printf("  ���ƾƾƾƾƾ� ����(F) ��!!");
    Sleep(2500);
    system("cls");
    ClearBuffer();
    gameState = 4;
    play = 0;
    CloseHandle(thread);

}

/* Ŀ����ġ */
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

        Sleep(1000); // 1�� ���
    }
    return 0;
}