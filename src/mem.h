#pragma once

#include<vector>

class Mem
{   
    int rom0_start;
    int romX_start;
    int vram_start;
    int sram_start;
    int wram0_start;
    int wramX_start;
    int echo_start;
    int oam_start;
    int ioReg_start;
    int hram_start;

    int rom0_size;
    int romX_size;
    int vram_size;
    int sram_size;
    int wram0_size;
    int wramX_size;
    int echo_size;
    int oam_size;
    int ioReg_size;
    int hram_size;

    std::vector<char> mem;

    Mem();
};