#pragma once

#include "piece.hpp"
#include "move.hpp"

struct board
{
    //          col   row
    piece array[7][7];
    board();
    void display();
    // these may need to go in another class...
    bool legal_move(move M);
    int winner();
    bool game_is_won();
};
