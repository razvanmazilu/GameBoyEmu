#include <raylib.h>
#include <raymath.h>
#include<vector>

class Screen
{
    int height;
    int width;

    std::vector<bool> data;

public:
    Screen(int height, int width);
    void Draw(Vector2 startPos);
    void Reset();
    void ChangePixelState(Vector2 pixel);

};