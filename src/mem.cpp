#include"mem.h"

Mem::Mem()
{
    rom0_start  = 0x0000;
    romX_start  = 0x4000;
    vram_start  = 0x8000;
    sram_start  = 0xA000;
    wram0_start = 0xC000;
    wramX_start = 0xD000;
    echo_start  = 0xE000;
    oam_start   = 0xFE00;
    ioReg_start = 0xFF00;
    hram_start  = 0xFF80;

    rom0_size = 0x4000;
    romX_size = 0x4000;
    vram_size = 0x2000;
    sram_size = 0x2000;
    wram0_size = 0x1000;
    wramX_size = 0x1000;
    echo_size;
    oam_size;
    ioReg_size;
    hram_size;

    std::fill(mem.begin(), mem.end(), 0);
}