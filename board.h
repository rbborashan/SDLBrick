#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

// TODO: Adjustable layout size
// TODO: Different grid layouts
struct Layout
{
    int rows = 7;
    int columns = 9;
    char grid [(7*9)+1] = {
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        '\0'
    };
};

class Board
{
private:
    int w_width;
    int w_height;
    Piece* pieces;

public:
    Board();
    Board(int, int, Layout);
    ~Board();

    void getWindowSize(int*, int*);
};

#endif // BOARD_H
