#include "piece.h"

//------------------------------------------------------------------------------
Piece::Piece() {}

Piece::Piece(int _x, int _y)
{
    x = _x;
    y = _y;

    // Give fixed size here for now
}

Piece::Piece(int _x, int _y, int _w, int _h)
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;
}

Piece::Piece(int _x, int _y, int _w, int _h, Color c)
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;

    setColor(c);
}

//------------------------------------------------------------------------------
void Piece::setXY(int _x, int _y)
{
    // Pass a negative value to avoid changing the respective coordinate
    if (_x >= 0)
        x = _x;
    if (_y >= 0)
        y = _y;
}

void Piece::setSize(int _w, int _h)
{
    // Pass a negative value to avoid changing the respective length
    if (_w >= 0)
        w = _w;
    if (_h >= 0)
        h = _h;
}

void Piece::setRGBA(unsigned char _r, unsigned char _g,
                    unsigned char _b, unsigned char _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Piece::setColor(Color color)
{
    r = color.red;
    g = color.green;
    b = color.blue;
    a = color.alpha;
}

//------------------------------------------------------------------------------
int Piece::getX()
{
    return x;
}

int Piece::getY()
{
    return y;
}

int Piece::getWidth()
{
    return w;
}

int Piece::getHeight()
{
    return h;
}

int Piece::getXOffset()
{
    return x + w;
}

int Piece::getYOffset()
{
    return y + h;
}
//------------------------------------------------------------------------------
