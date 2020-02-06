#include <cstddef>
#include "board.h"
#include "colors.h"

//------------------------------------------------------------------------------
Board::Board()
{
    w_width = 1200;
    w_height = 700;
}

Board::Board(int _w_width, int _w_height, Layout layout)
{
    Piece* piece = NULL;
    int index = 0;

    w_width = _w_width;
    w_height = _w_height;
    pieces = new Piece[layout.rows * layout.columns];

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            piece = &pieces[index++];

            piece->setXY(col * 70, row * 60);
            piece->setSize(60, 20);
            piece->setRGBA(COL_WHITE);
        }
    }
}

Board::~Board()
{
    delete pieces;
    pieces = NULL;
}

//------------------------------------------------------------------------------
void Board::getWindowSize(int* width, int* height)
{
    *width = w_width;
    *height = w_height;
}

void Board::renderBoard(SDL_Renderer* renderer)
{
    Color c;
    SDL_Rect srcrect;
    Piece* piece = NULL;
    int index = 0;

    static bool rendered = false;

    if (!rendered) // draw only once
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLUMNS; col++)
            {
                piece = &pieces[index++];

                // Get color + coordinates
                c = piece->getColor();
                srcrect.x = piece->getX();
                srcrect.y = piece->getY();
                srcrect.w = piece->getWidth();
                srcrect.h = piece->getHeight();

                // Render piece
                SDL_SetRenderDrawColor(renderer, c.red, c.green, c.blue, c.alpha);
                SDL_RenderFillRect(renderer, &srcrect);
            }
        }
        rendered = true;
    }
}

//------------------------------------------------------------------------------
