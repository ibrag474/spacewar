#include "object.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Object {
private:
public:
    Enemy();
    Enemy(int, int);
    ~Enemy() {};
    void moveDown();
};

#endif // ENEMY_H
