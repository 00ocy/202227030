#pragma once
#include <chrono>
#include <thread>
#include "Scene.h"


using namespace std;

namespace OCY_12
{
	class GameLoop
	{
	private:
		bool _isGameRunning;
		Scene sRenderer;
		
		Word* w;
	public:
		GameLoop() 
		{ 
			_isGameRunning = false; 
			w = nullptr;
		}
		~GameLoop() {}

		void Run()
		{

			_isGameRunning = true;
			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Scene();
				
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}
	private:
		void Initialize()
		{
		}

		void Release()
		{
		}

		void Input()
		{
			sRenderer.abc();
		}

		void Update()
		{
		}

		
		void Scene()
		{			
			//sRenderer.MoveCursor(w.x, w.y);
			sRenderer.Draw();			
		}
	};
}