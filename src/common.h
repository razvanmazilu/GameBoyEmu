#pragma once

#include<raylib.h>
#include<iostream>

enum vbLvl {
    LOW,
    HIGH
};

namespace constants 
{
    extern const Color darkestGreen;
    extern const Color darkGreen;
    extern const Color lightGreen;
    extern const Color lightestGreen;

    extern double lastUpdateTime;
}

bool eventTriggered(double interval);