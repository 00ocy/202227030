//#include <iostream>
//#include <Windows.h>
//#include <chrono>
//#include <thread>
//#include "Scene.h"
//#include <vector>
//#include "Object.h"
//#include "GameLoop.h"
//
//
//using namespace std;
//
//namespace OHCHAN_12
//{
//    
//    
//    Scene::Scene() 
//    {
//    }
//
//    Scene::~Scene()
//    {
//        
//
//        //// �Ҹ��ڿ��� objects ���Ϳ� ��� ������Ʈ���� �����մϴ�.
//        //for (Object* object : objects)
//        //{
//        //    delete object;
//        //}
//    }
//    
//
//    void OHCHAN_12::Scene::Addbuf(int x, int y, std::string info)
//    {
//        if (gamestate == 1)
//        {
//            if (y >= 0 && y < PlayScene.size() && x >= 0 && x + info.length() <= PlayScene[y].length())
//            {
//                std::string& line = PlayScene[y];
//                for (int i = 0; i < info.length(); i++)
//                {
//                    line[x + i] = info[i];
//                }
//            }
//        }
//    }
//
//
//    void OHCHAN_12::Scene::SceneRender()
//    {
//
//        //�����÷��� ȭ��
//        if (gamestate == 1)
//        {
//            //PlayScene.resize(HEIGHT, std::string(WIDTH, ' '));
//            
//             // ������ �׸���
//            for (int i = 0; i < VIEW_HEIGHT; i++) {
//                for (int j = 0; j < VIEW_WIDTH; j++) {
//                    int mapX = snake.getX() - (VIEW_WIDTH / 2) + j;
//                    int mapY = snake.getY() - (VIEW_HEIGHT / 2) + i;
//
//                    // �׵θ��� ���
//                    if (mapX < 0 || mapX >= WIDTH || mapY < 0 || mapY >= HEIGHT) {
//                        cout << "#"; // �׵θ� ����
//                    }
//                    // ������ ����
//                    else if (i == 0 || i == VIEW_HEIGHT - 1 || j == 0 || j == VIEW_WIDTH - 1) {
//                        cout << "*"; // �׵θ�
//                    }
//                    else {
//                        // ���� ��ġ
//                        if (mapX == snake.getX() && mapY == snake.getY()) {
//                            cout << "O";
//                        }
//                        // ������ ��ġ
//                        else {
//                            bool isTail = false;
//                            for (int k = 0; k < tail.size(); k++) {
//                                if (tail[k].getX() == mapX && tail[k].getY() == mapY) {
//                                    cout << "o";
//                                    isTail = true;
//                                    break;
//                                }
//                            }
//                            if (!isTail) {
//                                cout << " ";
//                            }
//                        }
//                    }
//                }
//                cout << endl;
//            }
//            
//           
//
//        
//        }
//
//
//        if (gamestate == 0)
//        {      
//            std::cout << "******************************************" << std::endl;
//            std::cout << "*                                        *" << std::endl;
//            std::cout << "*                                        *" << std::endl;
//            std::cout << "*              ������ ����               *" << std::endl;
//            std::cout << "*             (Snake  Bite)              *" << std::endl;
//            std::cout << "*                                        *" << std::endl;
//            std::cout << "*      ���� ����                         *" << std::endl;
//            std::cout << "*      ���� ����                         *" << std::endl;
//            std::cout << "*      ���� ��ŷ ����                    *" << std::endl;
//            std::cout << "*      ���� ���� (esc)                   *" << std::endl;
//            std::cout << "******************************************" << std::endl;
//
//
//
//
//
//            //TitleScene.resize(height, std::string(width, ' '));
//
//            //// Ư�� ��ġ�� ���ڿ� �ֱ�
//            //int x = 10;  // x ��ǥ (0���� ����)
//            //int y = 5;   // y ��ǥ (0���� ����)
//            //std::string str = "��ο�";
//
//            //// screenBuf�� Ư�� ��ġ�� ���ڿ� ����
//            //TitleScene[y].replace(x, str.length(), str);
//
//            //for (const std::string& line : TitleScene)
//            //{
//            //    std::cout << line << std::endl;
//            //}
//            
//        }
//    }
//
//    void Scene::Clear()
//    {
//        // ���۸� �������� �ʱ�ȭ
//        for (int i = 1; i < HEIGHT - 1; ++i)
//        {
//            for (int j = 1; j < WIDTH - 1; ++j)
//            {
//                PlayScene[i][j] = ' ';
//            }
//        }
//    }
//
//}
//
