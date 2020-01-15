#include "view.h"

View::View()
{
    board = new Board;
}

View::View(Board* _board)
{
    board = _board;
}

View::~View()
{
    delete board;
    board = NULL;
}
