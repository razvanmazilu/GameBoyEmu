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

Vector2 operator *(Vector2 &vec, int i)
{
    vec.x = vec.x * i;
    vec.y = vec.y * i;
    return vec;
}

Vector2 operator +=(Vector2 &des, const Vector2 &source)
{
    des.x = des.x + source.x;
    des.y = des.y + source.y;
    return des;
}
struct PacMan {
public:
    Vector2 currentPos = {offset + static_cast<float>(cellSize*cellCount/2), offset + static_cast<float>(cellSize*cellCount/2)};
    /* 
    (1,0) right
    (0,1) down
    (-1,0) left
    (0,-1)up
    */
    Vector2 direction = {0, 0};

    void Move()
    {
        if(eventTriggered(0.2)) 
        {
            Draw(black);
            currentPos += (direction * 2);
            Draw(yellow);
        } 
    }
    void SetDirection() 
    {
        if(IsKeyPressed(KEY_UP)) 
        {
            direction = {0, -1};
        }

        if(IsKeyPressed(KEY_DOWN)) 
        {
            direction = {0, 1};
        }

        if(IsKeyPressed(KEY_LEFT)) 
        {
            direction = {-1, 0};
        }

        if(IsKeyPressed(KEY_RIGHT)) 
        {
            direction = {1, 0};
        }
        Move();
    }
    void Draw(Color color)
    {
        DrawCircleV(currentPos, cellSize/2 - 2, color);
    }

    void DrawMouth(Color color, int open, Vector2 direction) 
    {
        float startAngle = 0.0;
        float endAngle = 0.0;
        Draw(yellow);
        if ((open >= 3) || (open < 0))
        {
            std::cout <<"invalid parameter open:"<<open<<std::endl;
        }
        else if(direction.x == 1 && direction.y == 0)
        {
            startAngle = -15;
            endAngle = 15;
        }
        else if (direction.x == -1 && direction.y == 0)
        {
            startAngle = 175;
            endAngle = 195;
        }

        else if (direction.x == 0 && direction.y == -1)
        {
            startAngle = 255;
            endAngle = 285;
        }
        else if (direction.x == 0 && direction.y == 1)
        {
            startAngle = 75;
            endAngle = 105;
        }

        if (open == 0)
        {
            DrawCircleSector(currentPos, cellSize/2 -2, startAngle, endAngle, 10, color);
        }
        else if (open == 1)
        {
            DrawCircleSector(currentPos, cellSize/2 -2, startAngle - 30, endAngle + 30, 10, color);
        }
        else if (open == 2)
        {
            DrawCircleSector(currentPos, cellSize/2 -2, startAngle, endAngle, 10, color);
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
            DrawMouth(black, mouthOpen, direction);       
        }
        else
        {
            Draw(yellow);
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
                                            {0, 0, 0, 0, 0, 0, 0, 2, 3, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 4, 5, 5, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
        for (int i = 0; i < cellCount; i++) {
            for(int j = 0; j < cellCount; j++) {
                if (mazeArr[i][j] == 1) {

                    // draw 2 vertical lines for each 1 at limit + 2 and limit + 18
                    Vector2 start = {offset + 2 + static_cast<float>(cellSize * j), offset + static_cast<float>(cellSize * i)};
                    Vector2 end = {offset + 2 + static_cast<float>(cellSize * (j)), offset + static_cast<float>(cellSize * (i +1)) };
                    DrawLineEx(start, end, 2, darkBlue);
                    start = {offset + 18 + static_cast<float>(cellSize * j), offset + static_cast<float>(cellSize * i)};
                    end = {offset + 18 + static_cast<float>(cellSize * (j)), offset + static_cast<float>(cellSize * (i +1)) };
                    //DrawRectangle(offset + j * cellSize, offset + i * cellSize, cellSize, cellSize, darkBlue);
                    DrawLineEx(start, end, 2, darkBlue);
                
                } else if (mazeArr[i][j] == 5) {
                        // draw 2 orizontal lines for each 1 at limit + 2 and limit + 18
                    Vector2 start = {offset + static_cast<float>(cellSize * j), offset + 2 +  static_cast<float>(cellSize * i)};
                    Vector2 end = {offset + static_cast<float>(cellSize * (j + 1)), offset + 2 + static_cast<float>(cellSize * (i)) };
                    DrawLineEx(start, end, 2, darkBlue);
                    start = {offset + static_cast<float>(cellSize * j), offset + 18 + static_cast<float>(cellSize * i)};
                    end = {offset + static_cast<float>(cellSize * (j + 1)), offset +  18 + static_cast<float>(cellSize * (i)) };
                    //DrawRectangle(offset + j * cellSize, offset + i * cellSize, cellSize, cellSize, darkBlue);
                    DrawLineEx(start, end, 2, darkBlue);
                } 
                
                else if (mazeArr[i][j] == 4) {
                    // draw down left corner
                    Rectangle rec = { (offset + 1 + static_cast<float>(cellSize * j)), ((offset + 1 + static_cast<float>(cellSize * i))), static_cast<float>(cellSize - 2), static_cast<float>(cellSize - 2)};
                    DrawRectangleLinesEx(rec, 2, darkBlue); 
                    Vector2 start = {(offset + 1 + static_cast<float>(cellSize * j)),(offset + 2 + static_cast<float>(cellSize * i))};
                    Vector2 end;
                    end.x = start.x + static_cast<float>(cellSize - 2);
                    end.y = start.y;
                    DrawLineEx(start, end, 2, black);   
                    start.x = offset - 2  + static_cast<float>(cellSize * (j + 1));
                    start.y = offset + 1 + static_cast<float>(cellSize * (i));
                    end.x = start.x;
                    end.y = start.y + static_cast<float>(cellSize - 2);
                    DrawLineEx(start, end, 2, black);  
                }

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
        pacman.SetDirection();
        pacman.Animate();
       // if(drawMazeOnce) 
        {
            maze.Draw();
            drawMazeOnce = false;
        }

        //ClearBackground(black);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}