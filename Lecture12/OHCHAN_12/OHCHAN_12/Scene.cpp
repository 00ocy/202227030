#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Scene.h"

namespace OHCHAN_12
{
    
    Scene::Scene(int screenWidth, int screenHeight)
        : width(screenWidth), height(screenHeight)
    {
        
        // 버퍼 초기화
        buffer.resize(height, std::string(width, ' '));

        // 테두리 그리기
        for (int i = 0; i < width; ++i)
        {
            buffer[0][i] = '#';              // 윗쪽 테두리
            buffer[height - 1][i] = '#';     // 아랫쪽 테두리
        }
        for (int i = 0; i < height; ++i)
        {
            buffer[i][0] = '#';              // 왼쪽 테두리
            buffer[i][width - 1] = '#';      // 오른쪽 테두리
        }
    }

    Scene::~Scene()
    { 
        // 소멸자에서 objects 벡터에 담긴 오브젝트들을 삭제합니다.
        for (Object* object : objects)
        {
            delete object;
        }
    }


    void Scene::Addbuf(int x, int y, std::string info)
    {
        // 버퍼에 오브젝트들 정보 추가
        if (y >= 0 && y < buffer.size() && x >= 0 && x + info.length() <= buffer[y].length())
        {
            std::string& line = buffer[y];
            for (int i = 0; i < info.length(); i++)
            {
                line[x + i] = info[i];
            }
        }
    }
 
    void Scene::SceneRender()
    {
        // 화면에 버퍼 내용 출력
        for (const std::string& line : buffer)
        {
            std::cout << line << std::endl;
        }
    }

    void Scene::Clear()
    {
        // 버퍼를 공백으로 초기화
        for (int i = 1; i < height - 1; ++i)
        {
            for (int j = 1; j < width - 1; ++j)
            {
                buffer[i][j] = ' ';
            }
        }
    }

}
