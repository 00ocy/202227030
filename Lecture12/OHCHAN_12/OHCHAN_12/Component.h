#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
private:
    int posX;
    int posY;

public:
    Component(int x, int y) : posX(x), posY(y) {}
    virtual ~Component() {}

    virtual void Start() {}
    virtual void Update() {}
    virtual void Render() {}

    int GetX() { return posX; }
    int GetY() { return posY; }
    virtual std::string GetShape() { return "a"; }
};

#endif // COMPONENT_H