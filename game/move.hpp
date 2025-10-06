#pragma once
#include "position.hpp"

struct move
{
    position starting;
    position ending;
    move(position s,position e):starting(s),ending(e) {};
    bool valid_move(); 
};

