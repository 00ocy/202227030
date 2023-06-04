#ifndef OBJECT_H
#define OBJECT_H

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

#endif
