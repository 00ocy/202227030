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
        std::vector<std::string> buffer; // ȭ�� ����
        std::vector<Object*> objects; // Object ���� �߰�

    public:
        Scene(int screenWidth, int screenHeight);       
        ~Scene();

        void MoveCursor(short x, short y);
        void SetCursorState(bool visible);
        void DrawString(std::string s);
        void Clear();
        void Start();
        void Update();
        void AddObject(Object* object);
        void Addbuf(int x, int y, std::string info);
        void SceneRender();

    };
}
