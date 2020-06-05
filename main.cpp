#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>
#include "enemy.h"
#include "player.h"
#include "game.h"
#include <vector>
#include <fstream>

using namespace std;

void ClearScreen() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void init();
int handleInput();

int main()
{
    string vardas;
    int bulletX, bulletY, verticallyNearestEnemyIndex, moveDownEnemiesEveryFrameNumber = 100, framesAfterEnemiesMoveDown = 0;
    bool shot = false, hit = false;
    const double maxFPS = 60.0;
    const double maxPeriod = 1000 / maxFPS;
    long long int lastTime = 0;
    long long int currentTime = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();
    long long int deltaTime;
    cout << "Iveskite savo varda: ";
    cin >> vardas;
    init();
    Game game;
    game.loadLevel();
    Player player(50, 34);
    //game loop
    while (game.getRunningState()) {
        currentTime = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();
        deltaTime = currentTime - lastTime;
        if (deltaTime >= maxPeriod) {
            if (framesAfterEnemiesMoveDown >= moveDownEnemiesEveryFrameNumber) {
                game.moveDownEnemies();
                framesAfterEnemiesMoveDown = 0;
            } else {
                framesAfterEnemiesMoveDown++;
            }
            if (shot) {
                if (bulletY > 1) {
                    game.gotoxy(bulletX, bulletY);
                    cout << " ";

                    if (verticallyNearestEnemyIndex > -1) {
                        if (game.getEnemy(verticallyNearestEnemyIndex).getY() == bulletY) {
                            hit = true;
                            game.removeEnemy(verticallyNearestEnemyIndex);
                            game.increaseScore(10);
                        }
                    }
                    if (!hit) {
                        bulletY--;
                        game.gotoxy(bulletX, bulletY);
                        cout << 0;
                    } else {
                        hit = false;
                        shot = false;
                    }
                } else {
                    shot = false;
                    game.gotoxy(bulletX, bulletY);
                    cout << " ";
                }
        }

            if (handleInput() == 1) {
                game.gotoxy(player.getX(), player.getY());
                cout << " ";
                player.moveLeft();
                game.gotoxy(player.getX(), player.getY());
                cout << 0;
            } else if (handleInput() == 2) {
                game.gotoxy(player.getX(), player.getY());
                cout << " ";
                player.moveRight();
                game.gotoxy(player.getX(), player.getY());
                cout << 0;
            } else if (handleInput() == 3 && !shot) {
                bulletX = player.getX();
                bulletY = player.getY() - 1;
                verticallyNearestEnemyIndex = game.getVerticallyNearestEnemyIndex(bulletX);
                shot = true;
            }

            lastTime = currentTime;
        }
    }
    fstream rez;
    rez.open ("rezultatai.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    rez << vardas << " " << game.getScore() << endl;
    rez.close();
    system("pause");
    return 0;
}

void init() {
    system("cls");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    //MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, r.left, r.top, 800, 600, TRUE);
}

int handleInput() {
    if (GetKeyState('W') < 0) {
        return 3;
    } else if (GetKeyState('A') < 0) {
        return 1;
    } else if (GetKeyState('D') < 0) {
        return 2;
    }
}
