#include <iostream>
#include <raylib.h>

int offset = 20;
int cellSize = 20;
const int cellCount = 21;

//colors 

Color black = {0, 0, 0, 255};
Color darkBlue = {25, 25, 166, 255};
Color brightBlue = {33, 33, 222, 255};
Color red = {255, 0, 0, 255};
Color yellow = {255, 255, 0, 255};

double lastUpdateTime = 0;

double eventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

struct PacMan {
public:
    Vector2 startPos = {offset + static_cast<float>(cellSize*cellCount/2), offset + static_cast<float>(cellSize*cellCount/2)};

    void Draw()
    {
        DrawCircleV(startPos, cellSize/2 - 2, yellow);
    }

    void DrawMouth(Color color, int open) 
    {
        if ((open >= 3) || (open < 0))
        {
            std::cout <<"invalid parameter open:"<<open<<std::endl;
        }
        else 
        {
            if (open == 0)
            {
                DrawCircleSector(startPos, cellSize/2 -2, -15, 15, 10, color);
            }
            else if (open == 1)
            {
                 DrawCircleSector(startPos, cellSize/2 -2, -45, 45, 10, color);
            }
            else if (open == 2)
            {
                 DrawCircleSector(startPos, cellSize/2 -2, -15, 15, 10, color);
            }
        }
        
        //DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
    }
    void Animate() 
    {
        static int mouthOpen = 0;
        if(eventTriggered(0.2))
        {
            mouthOpen++;
        }
        
        mouthOpen = mouthOpen % 4;
        //Draw();
        if(mouthOpen < 3)
        {
            DrawMouth(black, mouthOpen);       
        }
        else
        {
            Draw();
        }
    }
};

struct Maze {
public:
    char mazeArr[cellCount][cellCount] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    void Draw() 
    {
        for (int i = 0; i < cellCount; i++)
            for(int j = 0; j < cellCount; j++) {
                if (mazeArr[i][j] == 1) {
                    DrawRectangle(offset + j * cellSize, offset + i * cellSize, cellSize, cellSize, darkBlue);
                }
            }
    }
};

int main () {

    std::cout << "Starting the game ..." << std::endl;
    InitWindow(2*offset + cellSize * cellCount, 2 * offset + cellSize*cellCount, "PacMan");
    SetTargetFPS(60);

    PacMan pacman;
    Maze maze;
    bool drawMazeOnce = true;
    while(WindowShouldClose() == false){

        BeginDrawing();

        Rectangle border = {static_cast<float>(offset-5), static_cast<float>(offset-5), static_cast<float>(cellSize*cellCount+10), static_cast<float>(cellSize*cellCount+10)};
        DrawRectangleLinesEx(border, 3, darkBlue);
        //pacman.Draw();

        pacman.Animate();
        maze.Draw();
        //ClearBackground(black);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}