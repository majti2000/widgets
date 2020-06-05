#include "teglalap.hpp"

teglalap::teglalap(int _a, int _b, int _w, int _h) : a(_a), b(_b), w(_w), h(_h)
{
}

bool teglalap::benne(int _x, int _y) 
{
    return _x>a && _x<a+w && _y>b && _y<b+h;
}
