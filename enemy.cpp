#include "enemy.h"

Enemy::Enemy() {
    setCoords(0, 0);
}

Enemy::Enemy(int x, int y) {
    setCoords(x, y);
}

void Enemy::moveDown() {
    int y = getY();
    y++;
    setY(y);
}
