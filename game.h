#ifndef GAME_H
#define GAME_H

#include "enemy.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Game {
private:
    vector<Enemy> enemies;
    ifstream file;
    int playerScore, retries, levelNumber, currentLevel;
    bool running;
    void drawStatusBar();
public:
    Game();
    ~Game() {};
    int getScore();
    void loadLevel();
    void drawEnemies();
    void addEnemy(int, int);
    void removeEnemy(int);
    Enemy getEnemy(int);
    void gotoxy(int, int);
    int getVerticallyNearestEnemyIndex(int);
    void increaseScore(int);
    bool getRunningState();
    void moveDownEnemies();
    void clearGameMap();
};

#endif // GAME_H
