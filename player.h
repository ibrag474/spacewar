#include "object.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player: public Object {
public:
    Player();
    Player(int, int);
    ~Player() {};
    void moveLeft();
    void moveRight();
};

#endif // PLAYER_H
