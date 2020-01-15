#ifndef PIECE_H
#define PIECE_H

#include "colors.h"

class Piece
{
private:
    // Coordinates
    int x, y;
    // Size
    int w, h;
    // Color (RBGA)
    unsigned char r, g, b, a;

public:
    Piece();
    Piece(int, int);
    Piece(int, int, int, int);
    Piece(int, int, int, int, Color);

    void setXY(int, int);
    void setSize(int, int);
    void setRGBA(unsigned char, unsigned char,
                 unsigned char, unsigned char);
    void setColor(Color);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getXOffset();
    int getYOffset();
};

#endif // PIECE_H
