#pragma once
#include "GameManager.h"

void mainMenu_Logic();
void gamePlay_Logic();
void gameDescription_Logic();
void option_Logic();
void playerDeath_Logic();

void generateAssignments();
void generateWalls();

bool isAssignmentInArray(int x, int y, struct Assignment* Assignments, int AssignmentNum);
bool isWallInArray(int x, int y, struct Wall* walls, int numWalls);

void PlayStart();
void PlayEnd();



void setCursorPos(int x, int y);


HANDLE thread;
DWORD threadId;
DWORD WINAPI updateAssignmentShapes();
