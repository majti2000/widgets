#include "statictext.hpp"
#include "graphics.hpp"

using namespace genv;

statictext::statictext(int x, int y, std::string szoveg)
    : Widget(x,y,gout.twidth(szoveg)+10,gout.cascent()+gout.cdescent()+10), szov(szoveg)
{
}

void statictext::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(gout.twidth(szov)+10,gout.cascent()+gout.cdescent()+10) 
        << move_to(_x+_size_x/9, _y+_size_y/2) << color(0,0,0) << text(szov);
}

void statictext::handle(event ev)
{
}