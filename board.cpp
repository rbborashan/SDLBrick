#include <cstddef>
#include "board.h"

Board::Board()
{
    w_width = 1200;
    w_height = 700;
}

Board::Board(int _w_width, int _w_height, Layout layout)
{
    w_width = _w_width;
    w_height = _w_height;
    pieces = new Piece[layout.rows * layout.columns];
}

Board::~Board()
{
    delete pieces;
    pieces = NULL;
}

void Board::getWindowSize(int* width, int* height)
{
    *width = w_width;
    *height = w_height;
}
