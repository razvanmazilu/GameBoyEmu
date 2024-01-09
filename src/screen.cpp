#include "screen.h"
#include <iostream>

Screen::Screen(int height, int width)
{
    this->height = height;
    this->width = width;

    //data.reserve(height*width);
    data.resize(height*width);
    Reset();
}

void Screen::Draw(Vector2 startPos)
{
    DrawRectangleLines(startPos.x, startPos.y, 2*width, 2*height, WHITE);
    
    int index = 0;
    for(auto it = data.begin(); it != data.end(); it++)
    {
        index++;
        if(*it == 1)
        {
            DrawRectangle(2*(index/width), 2*(index%height),2 ,2, WHITE);
        }
    }
}

void Screen::DebugDraw(Vector2 startPos)
{
    static int roll = 0;

    DrawRectangle(startPos.x+1, startPos.y+1+ (roll   %4)*(2*height -2)/4, (2*width-2), (2*height -2)/4, constants::darkestGreen);
    DrawRectangle(startPos.x+1, startPos.y+1+((roll+1)%4)*(2*height -2)/4, (2*width-2), (2*height -2)/4, constants::darkGreen);
    DrawRectangle(startPos.x+1, startPos.y+1+((roll+2)%4)*(2*height -2)/4, (2*width-2), (2*height -2)/4, constants::lightGreen);
    DrawRectangle(startPos.x+1, startPos.y+1+((roll+3)%4)*(2*height -2)/4, (2*width-2), (2*height -2)/4, constants::lightestGreen);
    
    roll++;
}

void Screen::Reset()
{
    std::fill(data.begin(), data.end(), 0);
}

void Screen::ChangePixelState(Vector2 pixel)
{

    bool  d = data.at(pixel.x * width + pixel.y);
    d = !d;
    data.at(pixel.x * width + pixel.y) = d;
}

void Screen::DebugInfo(int verbosityLVL)
    {
        switch (verbosityLVL)
        {
            case LOW:
            {
                std::cout<< "( height :" << height << ",  width :" << width << " )" << std::endl;
                break;
            }
            case HIGH:
            {
                std::cout<< "( height :" << height << ",  width :" << width << " )" << std::endl;
                std::cout<<"( data:";
                for(auto elem : data)
                {
                    std::cout<<" "<<elem;
                }
                std::cout<<" )";
            }

        }
    }