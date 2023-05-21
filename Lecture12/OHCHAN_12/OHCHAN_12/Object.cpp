#include "Object.h"
#include <iostream>
#include <string>




void Object::Start()
{
    std::cout << "Object Start" << std::endl;
}

void Object::Update()
{
    std::cout << "Object Update" << std::endl;
}

void Object::Render()
{

    std::cout << "Object Render" << std::endl;
}

int Object::GetX()
{
    return posX;
}

int Object::GetY()
{
    return posY;
}

std::string Object::GetShape()
{
    return "б▄";
}



void Triangle::Start()
{
    std::cout << "Object Render" << std::endl;
}

void Triangle::Update()
{
    std::cout << "Object Render" << std::endl;
}

void Triangle::Render()
{
    
}

int Triangle::GetX()
{
    return posX;
}

int Triangle::GetY()
{
    return posY;
}

std::string Triangle::GetShape()
{
    return "бу";
}



void Square::Start()
{
    std::cout << "Object Render" << std::endl;
}

void Square::Update()
{
    std::cout << "Object Render" << std::endl;
}

void Square::Render()
{
    std::cout << "Object Render" << std::endl;
}

int Square::GetX()
{
    return posX;
}

int Square::GetY()
{
    return posY;
}

std::string Square::GetShape()
{
    return "бс";
}
