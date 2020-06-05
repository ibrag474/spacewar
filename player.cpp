#include "player.h"

Player::Player() {
    setCoords(0, 0);
}

Player::Player(int x, int y) {
    setCoords(x, y);
}

void Player::moveLeft() {
    int x = getX();
    if (x > 0) x--;
    setX(x);
}

void Player::moveRight() {
    int x = getX();
    if (x < 94) x++;
    setX(x);
}
