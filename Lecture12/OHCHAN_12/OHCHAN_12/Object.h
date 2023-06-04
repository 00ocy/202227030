#ifndef OBJECT_H
#define OBJECT_H

#include <string>
namespace OHCHAN_12
{

class Object {
private:
    int posX;
    int posY;

public:
    Object(int x, int y) : posX(x), posY(y) {}
    virtual ~Object() {}

    virtual void Start() {}
    virtual void Update() {}
    virtual void Render() {}

    int GetX() { return posX; }
    int GetY() { return posY; }
    virtual std::string GetShape() { return "a"; }
};

class Snake {
public:
    Snake(int startX, int startY) : x(startX), y(startY) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

private:
    int x;
    int y;
};

class Circle : public Object {
public:
    Circle(int x, int y) : Object(x, y) {}

    std::string GetShape() override
    {
        return "б▄";
    }


};

class Triangle : public Object {
public:
    Triangle(int x, int y) : Object(x, y) {}

    std::string GetShape() override 
    {
        return "бу";
    }
    

};

class Square : public Object {
public:
    Square(int x, int y) : Object(x, y) {}

    std::string GetShape() override
    {
        return "бс";
    }


};


}

#endif // OBJECT_H
