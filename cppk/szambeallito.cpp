#include "szambeallito.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

Szambeallito::Szambeallito(int x, int y, int szelesseg, int magassag, int al, int fel, int ertekaminemszamit)
    : Widget(x,y,szelesseg,magassag), ertek(ertekaminemszamit), 
     felso(x+szelesseg-20, y, 20, magassag/2), 
     also(x+szelesseg-20, y+magassag/2, 20, magassag/2), 
     alhat(al), fenhat(fel)
{
}


void Szambeallito::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout << color(255,255,255) ;

    gout << move_to(_x+3, _y+_size_y/2) << text(to_string(ertek));

    gout << move_to(felso.a,felso.b) << box(felso.w,felso.h) << color(0,0,0) 
         << move_to(felso.a+2,felso.b+2) << box(felso.w-4, felso.h-4) << color(255,255,255) 
         << move_to(felso.a+_size_y/5,also.b) << text("^");

    gout << move_to(felso.a,also.b) << box(felso.w,felso.h) << color(0,0,0) 
         << move_to(felso.a+2,also.b+2) << box(felso.w-4, felso.h-4)
         << color(255,255,255) << move_to(felso.a+_size_y/5,felso.b+felso.w+_size_y/3) << text("v");
}

void Szambeallito::handle(event ev)
{
    if (ev.button==btn_left && felso.benne(ev.pos_x, ev.pos_y))
    {
        ertek++;
    }
    if (ev.button==btn_left && also.benne(ev.pos_x, ev.pos_y))
    {
        ertek--;
    }
    if (ev.keycode==key_up){
         ertek++;
    }
    if (ev.keycode==key_down){
        ertek--;
    }
    if (ev.keycode==key_pgup){
        ertek+=10;
    }
    if (ev.keycode==key_pgdn){
        ertek-=10;
    }
    if (ertek > fenhat){
        ertek=fenhat;
    }
    if (ertek < alhat){
        ertek=alhat;
    }
}
