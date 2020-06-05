#include "game.h"

Game::Game() {
    running = true;
    retries = 2;
    playerScore = 0;
    file.open("config.txt");
    file >> levelNumber;
    file.close();
    currentLevel = 1;
    drawStatusBar();
}

void Game::drawStatusBar() {
    gotoxy(0,0);
    cout << "SCORE:";
    gotoxy(18, 0);
    cout << "Level:";
    gotoxy(29, 0);
    cout << "Retries left:";
    gotoxy(43, 0);
    cout << retries;
}

int Game::getScore() {
    return playerScore;
}

void Game::drawEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        gotoxy(enemies[i].getX(), enemies[i].getY());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << 0;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(25, 0);
    cout << currentLevel;
}

void Game::addEnemy(int x, int y) {
    enemies.push_back(Enemy(x, y));
}

void Game::gotoxy(int x, int y) {
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Game::getVerticallyNearestEnemyIndex(int x) {
    int maxY = -1, index = -1;
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].getX() == x && enemies[i].getY() > maxY) {
            maxY = enemies[i].getY();
            index = i;
        }
    }
    return index;
}

void Game::removeEnemy(int index) {
    if (enemies.size() > index) {
        gotoxy(enemies[index].getX(), enemies[index].getY());
        cout << " ";
        enemies.erase(enemies.begin() + index);
    }
    if (enemies.size() == 0 && (currentLevel < levelNumber)) {
        currentLevel++;
        this->loadLevel();
    } else if (currentLevel == levelNumber) {
        running = false;
    }
}

Enemy Game::getEnemy(int index) {
    return enemies[index];
}

void Game::increaseScore(int score) {
    playerScore += score;
    gotoxy(7, 0);
    cout << playerScore << endl;
}

void Game::loadLevel() {
    int x, y;
    file.open(to_string(currentLevel) + ".txt");
    while (!file.eof()) {
        file >> x >> y;
        enemies.push_back(Enemy(x, y));
    }
    drawEnemies();
    file.close();
}

bool Game::getRunningState() {
    return running;
}

void Game::moveDownEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].getY() > 33) {
            if (retries > 0) {
                retries--;
                enemies.clear();
                clearGameMap();
                loadLevel();
                break;
            } else {
                running = false;
                system("cls");
                cout << "Pralaimejote :(" << endl;
                break;
            }
        } else {
            gotoxy(enemies[i].getX(), enemies[i].getY());
            cout << " ";
            enemies[i].moveDown();
            drawEnemies();
        }
    }
}

void Game::clearGameMap() {
    system("cls");
    drawStatusBar();
}
