#include "screen.h"

Screen::Screen(int height, int width)
{
    this->height = height;
    this->width = width;

    data.reserve(height*width);
    Reset();
}

void Screen::Draw(Vector2 startPos)
{
    DrawRectangleLines(startPos.x, startPos.y, 2*width, 2*height, WHITE);
}

void Screen::Reset()
{
    std::fill(data.begin(), data.end(), 0);
}
