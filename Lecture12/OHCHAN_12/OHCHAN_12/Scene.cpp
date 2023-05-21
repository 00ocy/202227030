#include "Scene.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

namespace OHCHAN_12
{
    void Scene::MoveCursor(short x, short y)
    {
        COORD position = { x , y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    }

    void Scene::SetCursorState(bool visible)
    {
        CONSOLE_CURSOR_INFO consoleCursorInfo;
        consoleCursorInfo.bVisible = visible;
        consoleCursorInfo.dwSize = 1;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
    }

    Scene::Scene(int screenWidth, int screenHeight)
        : width(screenWidth), height(screenHeight)
    {
        
        // ���� �ʱ�ȭ
        buffer.resize(height, std::string(width, ' '));

        // �׵θ� �׸���
        for (int i = 0; i < width; ++i)
        {
            buffer[0][i] = '#';              // ���� �׵θ�
            buffer[height - 1][i] = '#';     // �Ʒ��� �׵θ�
        }
        for (int i = 0; i < height; ++i)
        {
            buffer[i][0] = '#';              // ���� �׵θ�
            buffer[i][width - 1] = '#';      // ������ �׵θ�
        }
    }

    Scene::~Scene()
    { 
        // �Ҹ��ڿ��� objects ���Ϳ� ��� ������Ʈ���� �����մϴ�.
        for (Object* object : objects)
        {
            delete object;
        }
    }

    void Scene::AddObject(Object* object)
    {
        // ������Ʈ�� ���Ϳ� �߰��մϴ�.
        objects.push_back(object);
    }

    void Scene::Addbuf(int x, int y, std::string info)
    {
        // ���ۿ� ������Ʈ�� ���� �߰�
        if (y >= 0 && y < buffer.size() && x >= 0 && x + info.length() <= buffer[y].length())
        {
            std::string& line = buffer[y];
            for (int i = 0; i < info.length(); i++)
            {
                line[x + i] = info[i];
            }
        }
    }
 
    void Scene::DrawString(std::string s)
    {
        std::cout << s;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    void Scene::SceneRender()
    {
        // ȭ�鿡 ���� ���� ���
        for (const std::string& line : buffer)
        {
            std::cout << line << std::endl;
        }
    }

    void Scene::Clear()
    {
        // ���۸� �������� �ʱ�ȭ
        for (int i = 1; i < height - 1; ++i)
        {
            for (int j = 1; j < width - 1; ++j)
            {
                buffer[i][j] = ' ';
            }
        }
    }

}
