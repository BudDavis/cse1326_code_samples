#pragma once
struct piece
{
    int color;  // for now, 0=black, 1 = red.  should be an enum
    int row;
    int col;
    bool king;
};
