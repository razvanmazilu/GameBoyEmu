    #include"common.h"
    
    const Color constants::darkestGreen = {15, 56, 15, 255};
    const Color constants::darkGreen = {48, 98, 48, 255};
    const Color constants::lightGreen = {139, 172, 15, 255};
    const Color constants::lightestGreen = {155, 188, 15, 255};

    double constants::lastUpdateTime = 0;
    
    bool eventTriggered(double interval) 
    {

        double currentTime = GetTime();

        if(currentTime - constants::lastUpdateTime >= interval) 
        {
            constants::lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }