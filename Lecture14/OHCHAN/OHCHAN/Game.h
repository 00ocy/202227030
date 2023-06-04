//#pragma once
//
//
//#define INITIAL_LENGTH 5 // 뱀 초기 길이
//#define MAX_LENGTH 100   // 뱀 최대 길이
//
//
///*** 게임 상태 ***/
//int gameState;  // 게임 상태
//
///** gameState0 메인메뉴 **/
//int menuSelect; // 메뉴 선택
//
///** gameState1 게임화면 **/
///* 맵 */
//void ReStart(); // 재시작
//
//// void SetColor(unsigned short backgroundColor, unsigned short textColor); 색 바꾸기 
//
///* 과제 */
//int Lecture;
//int A;
//int B;
//int C;
//int Progress;
//   //             Lecture = NUM_FRUITS;
//DWORD WINAPI updateFruitShapes(LPVOID arg); // 스레드 (비동기로 학점 바꾸기 위한 스레드)
//void generateFruits(); //과제 생성
//void handleFruitCollision(); // 과제 충돌 관리
//void stringA();       
//void stringB();
//void stringC();
//void stringLecture();
//void stringProgress();
//void Jumsu();
//void stringJumsu();
//
///* 벽 */
//void generateWalls(); //벽 생성
//void handleWallCollision(); //벽 충돌 관리
//
//
///* 뱀 */
//Snake snake; // 구조체 뱀 인스턴스
//Snake tail[MAX_LENGTH]; // 뱀의 꼬리 (꼬리의 위치를 기록하기 위한 배열)
//int tailLength; // 현재 길이
//
//
///** gameState3 옵션 **/
//int mode; // 난이도
//int speed; // 게임 속도
//
