#include <cstddef>
#include "board.h"
#include "colors.h"

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

    for (int row = 0; row < 1; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            pieces[row * ROWS + col].setXY(row * 10, col * 50);
            pieces[row * ROWS + col].setSize(50, 10);
            pieces[row * ROWS + col].setRGBA(COL_WHITE);
        }
    }
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

void Board::renderBoard(SDL_Renderer* renderer)
{
    int x = 10;
    int y = 10;
    Color c;
    SDL_Rect srcrect;

    for (int row = 0; row < 1; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            // Get color + coordinates
            c = pieces[row*col].getColor();
            srcrect.x = pieces[row*col].getX();
            srcrect.y = pieces[row*col].getY();
            srcrect.w = pieces[row*col].getWidth();
            srcrect.h = pieces[row*col].getHeight();

            // Render piece
            SDL_SetRenderDrawColor(renderer, c.red, c.green, c.blue, c.alpha);
            SDL_RenderDrawRect(renderer, &srcrect);

            // Add gap between pieces
            x += (pieces[row * ROWS + col].getXOffset() + 20);
        }

        // Add gap between pieces
        y += (pieces[row * ROWS].getYOffset() + 20);
    }
}
