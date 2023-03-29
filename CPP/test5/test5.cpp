#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

class Coordinate {
public:
    int x, y;
    Coordinate(int x = 0, int y = 0) : x(x), y(y) {}
};

class ConsoleGameScreen {
public:
    static const int ScreenYSize = 20;
    static const int ScreenXSize = 40;
    static ConsoleGameScreen NewScreen;
    char Screen[ScreenYSize][ScreenXSize];

    void ClearScreen() {
        for (int i = 0; i < ScreenYSize; i++) {
            for (int j = 0; j < ScreenXSize; j++) {
                Screen[i][j] = 'a';
            }
        }
    }

    void DrawScreen() const {
        for (int i = 0; i < ScreenYSize; i++) {
            for (int j = 0; j < ScreenXSize; j++) {
                std::cout << Screen[i][j];
            }
            std::cout << std::endl;
        }
    }

    bool IsOutOfBoundary(const Coordinate& coord) const {
        return coord.x < 0 || coord.x >= ScreenXSize || coord.y < 0 || coord.y >= ScreenYSize;
    }

    void SetScreenCharacter(const Coordinate& coord, char ch) {
        if (!IsOutOfBoundary(coord)) {
            Screen[coord.y][coord.x] = ch;
        }
    }
};

ConsoleGameScreen ConsoleGameScreen::NewScreen;

class Bullet {
public:
    Coordinate position;
    Coordinate velocity;
    char symbol;

    Bullet(const Coordinate& pos, const Coordinate& vel, char sym) : position(pos), velocity(vel), symbol(sym) {}

    void Move() {
        position.x += velocity.x;
        position.y += velocity.y;
    }
};

class Player {
public:
    Coordinate position;
    char symbol;
    std::vector<Bullet> bullets;

    Player(const Coordinate& pos, char sym) : position(pos), symbol(sym) {}

    void MoveLeft() {
        position.x--;
        if (position.x < 0) {
            position.x = 0;
        }
    }

    void MoveRight() {
        position.x++;
        if (position.x >= ConsoleGameScreen::ScreenXSize) {
            position.x = ConsoleGameScreen::ScreenXSize - 1;
        }
    }

    void Fire() {
        bullets.push_back(Bullet({ position.x, position.y - 1 }, { -1, 0 }, '-'));
    }

    void Draw(ConsoleGameScreen& screen) const {
        screen.SetScreenCharacter(position, symbol);
        for (const Bullet& bullet : bullets) {
            screen.SetScreenCharacter(bullet.position, bullet.symbol);
        }
    }

    void Update() {
        for (Bullet& bullet : bullets) {
            bullet.Move();
        }
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
            [&](const Bullet& bullet) {
                return screen.IsOutOfBoundary(bullet.position);
            }), bullets.end());
    }

private:
    ConsoleGameScreen screen;
};

int main() {
    ConsoleGameScreen::NewScreen.ClearScreen();
    Player player({ ConsoleGameScreen::ScreenXSize / 2, ConsoleGameScreen::ScreenYSize - 1 }, '^');
    while (true) {

        ConsoleGameScreen::NewScreen.ClearScreen();
        player.Draw(ConsoleGameScreen::NewScreen);
        ConsoleGameScreen::NewScreen.DrawScreen();
        player.Update();
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a') {
                player.MoveLeft();
            }
            else if (ch == 'd') {
                player.MoveRight();
            }
            else if (ch == ' ') {
                player.Fire();
            }
        }
        Sleep(50);
    }
    return 0;
}