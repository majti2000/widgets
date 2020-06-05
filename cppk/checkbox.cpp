#include "checkbox.hpp"
#include "graphics.hpp"

using namespace genv;

CheckBox::CheckBox(int x, int y, int wx, int hy)
    : Widget(x,y,wx,hy), checked(false)
{
}

void CheckBox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    if (checked)
    {
        gout << move_to(_x+4, _y+4) << color(255,255,255) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
}

void CheckBox::handle(event ev)
{
    if (ev.type == ev_key && ev.keycode == key_enter) {
            checked = !checked;
    } 
    if (ev.type == ev_mouse && ev.button==btn_left && kival(ev.pos_x, ev.pos_y)) {
        checked = !checked;
    }
}

bool CheckBox::checked_e() 
{
    return checked;
}
