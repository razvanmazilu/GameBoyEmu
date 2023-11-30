#include <iostream>
#include <raylib.h>

int offset = 20;
int cellSize = 20;
int cellCount = 25;

//colors 

Color black = {0, 0, 0, 255};
Color darkBlue = {25, 25, 166, 255};
Color brightBlue = {33, 33, 222, 255};
Color red = {255, 0, 0, 255};
Color yellow = {255, 255, 0, 255};

struct PacMan {
public:
    Vector2 startPos = {offset + static_cast<float>(cellSize*cellCount/2), offset + static_cast<float>(cellSize*cellCount/2)};

    void Draw()
    {
        DrawCircleV(startPos, cellSize/2, yellow);
    }

    void Draw()
    {
        DrawCircleV(startPos, cellSize/2, yellow);
    }

};

int main () {

    std::cout << "Starting the game ..." << std::endl;
    InitWindow(2*offset + cellSize * cellCount, 2 * offset + cellSize*cellCount, "PacMan");
    SetTargetFPS(60);

    PacMan pacman;
    while(WindowShouldClose() == false){

        BeginDrawing();

        Rectangle border = {static_cast<float>(offset-5), static_cast<float>(offset-5), static_cast<float>(cellSize*cellCount+10), static_cast<float>(cellSize*cellCount+10)};
        DrawRectangleLinesEx(border, 3, darkBlue);
        pacman.Draw();
        ClearBackground(black);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}