#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
    int coordX, coordY;
public:
    Object(): coordX(0), coordY(0) {};
    Object(int, int);
    ~Object() {};
    void setCoords(int, int);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
};

#endif // OBJECT_H
