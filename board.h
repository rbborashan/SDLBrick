#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>

#include "piece.h"

const int ROWS = 7;
const int COLUMNS = 9;

// TODO: Adjustable layout size
// TODO: Different grid layouts
struct Layout
{
    int rows = 7;
    int columns = 9;
    char grid [7*9] = {
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x',
        'x','x','x','x','x','x','x','x','x'
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
    void renderBoard(SDL_Renderer*);
};

#endif // BOARD_H
