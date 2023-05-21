#pragma once

#include <vector>
#include "Object.h"


namespace OHCHAN_12
{
    class Scene
    {
    private:
        int width;
        int height;
        std::vector<std::string> buffer; // 화면 버퍼
        std::vector<Object*> objects; // Object 벡터 추가

    public:
        Scene(int screenWidth, int screenHeight);       
        ~Scene();

        void Clear();        
        void Addbuf(int x, int y, std::string info);
        void SceneRender();

    };
}
