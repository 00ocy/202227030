#ifndef OBJECT_H
#define OBJECT_H

#include <string>


class Object
{
private:
    int posX;
    int posY;
public:
    Object(int x, int y) :  posX(x), posY(y) {}
    virtual ~Object() {}

    virtual void Start();
    virtual void Update();
    virtual void Render();

    virtual int GetX();
    virtual int GetY();
    virtual std::string GetShape();
};

class Triangle : public Object
{
private:
    int posX;
    int posY;

public:
    Triangle(int x, int y) : Object(x, y), posX(x), posY(y) {}
     ~Triangle() {}

    void Start() override;
    void Update() override;
    void Render() override;
    int GetX() ;
    int GetY() ;
    std::string GetShape();
};

class Square : public Object
{
private:
    int posX;
    int posY;

public:
    Square(int x, int y) : Object(x, y), posX(x), posY(y) {}
     ~Square() {}

    void Start() override;
    void Update() override;
    void Render() override;
    int GetX() ;
    int GetY() ;
    std::string GetShape() ;
};


#endif // OBJECT_H
