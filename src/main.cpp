#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "screen.h"

int main () {

    std::cout << "Starting the emulator ..." << std::endl;
    InitWindow(340, 650, "GameBoy");
    SetTargetFPS(60);
    
    Screen scr = Screen(144,160);
    Vector2 startPos{10,10};
    while(WindowShouldClose() == false){

        BeginDrawing();
        scr.Draw(startPos);
        ClearBackground(BLACK);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}