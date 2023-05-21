#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "GameLoop.h"
#include "Object.h"
#include "Scene.h"

int main()
{
    OHCHAN_12::GameLoop gameLoop;
    gameLoop.Run();
    
    return 0;
}
