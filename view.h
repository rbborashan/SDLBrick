#ifndef VIEW_H
#define VIEW_H

#include "board.h"

class View
{
private:
    Board* board;

public:
    View();
    View(Board*);
    ~View();

};

#endif // VIEW_H
