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
//        //// 소멸자에서 objects 벡터에 담긴 오브젝트들을 삭제합니다.
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
//        //게임플레이 화면
//        if (gamestate == 1)
//        {
//            //PlayScene.resize(HEIGHT, std::string(WIDTH, ' '));
//            
//             // 게임판 그리기
//            for (int i = 0; i < VIEW_HEIGHT; i++) {
//                for (int j = 0; j < VIEW_WIDTH; j++) {
//                    int mapX = snake.getX() - (VIEW_WIDTH / 2) + j;
//                    int mapY = snake.getY() - (VIEW_HEIGHT / 2) + i;
//
//                    // 테두리인 경우
//                    if (mapX < 0 || mapX >= WIDTH || mapY < 0 || mapY >= HEIGHT) {
//                        cout << "#"; // 테두리 라인
//                    }
//                    // 게임판 내부
//                    else if (i == 0 || i == VIEW_HEIGHT - 1 || j == 0 || j == VIEW_WIDTH - 1) {
//                        cout << "*"; // 테두리
//                    }
//                    else {
//                        // 뱀의 위치
//                        if (mapX == snake.getX() && mapY == snake.getY()) {
//                            cout << "O";
//                        }
//                        // 꼬리의 위치
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
//            std::cout << "*              지렁이 게임               *" << std::endl;
//            std::cout << "*             (Snake  Bite)              *" << std::endl;
//            std::cout << "*                                        *" << std::endl;
//            std::cout << "*      게임 시작                         *" << std::endl;
//            std::cout << "*      게임 설명                         *" << std::endl;
//            std::cout << "*      게임 랭킹 보기                    *" << std::endl;
//            std::cout << "*      게임 종료 (esc)                   *" << std::endl;
//            std::cout << "******************************************" << std::endl;
//
//
//
//
//
//            //TitleScene.resize(height, std::string(width, ' '));
//
//            //// 특정 위치에 문자열 넣기
//            //int x = 10;  // x 좌표 (0부터 시작)
//            //int y = 5;   // y 좌표 (0부터 시작)
//            //std::string str = "헬로우";
//
//            //// screenBuf의 특정 위치에 문자열 삽입
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
//        // 버퍼를 공백으로 초기화
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
