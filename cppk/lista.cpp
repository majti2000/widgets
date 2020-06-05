#include "lista.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace std;
using namespace genv;

Lista::Lista(int x, int y, int sx, int sy, vector<string> elemek)
    : Widget(x,y,sx,sy), elemek(elemek), teglalapok(teglalapok), kijelolt(false)
{
    kocka=-1;
}

void Lista::draw()
{
    for (int i=0; i < 4; i++){
        gout << move_to(_x, _y+(gout.cascent() + gout.cdescent())*(i+1)) << color(255,255,255) << box(_size_x, gout.cascent() + gout.cdescent());
        gout << move_to(_x+2, _y+(gout.cascent() + gout.cdescent())*(i+1)+2) << color (0,0,0) << box(_size_x-4, (gout.cascent() + gout.cdescent())-4);
        gout << color(255,255,255);
        gout << move_to(_x+4, _y+(gout.cascent() + gout.cdescent())*(i+1)+(gout.cascent() + gout.cdescent())-3) << text(elemek[i]);
    }
    if (kijelolt){
        for (int i=0; i < 4; i++){
            gout << move_to(_x, _y+(gout.cascent() + gout.cdescent())*(i+1)) << color(255,255,255) << box(_size_x, gout.cascent() + gout.cdescent());
            gout << move_to(_x+2, _y+(gout.cascent() + gout.cdescent())*(i+1)+2) << color (0,0,0) << box(_size_x-4, (gout.cascent() + gout.cdescent())-4);
            gout << color(255,255,255);
            gout << move_to(_x+4, _y+(gout.cascent() + gout.cdescent())*(i+1)+(gout.cascent() + gout.cdescent())-3) << text(elemek[i]);
            if (i==kocka){
                gout << move_to(_x, _y+(gout.cascent() + gout.cdescent())*(i+1)) << color(255,255,255) << box(_size_x, gout.cascent() + gout.cdescent());
                gout << move_to(_x+2, _y+(gout.cascent() + gout.cdescent())*(i+1)+2) << color (128,0,0) << box(_size_x-4, (gout.cascent() + gout.cdescent())-4);
                gout << color(255,255,255);
                gout << move_to(_x+4, _y+(gout.cascent() + gout.cdescent())*(i+1)+(gout.cascent() + gout.cdescent())-3) << text(elemek[i]);
            }
        }
    }
}

void Lista::handle(event ev)
{
    if (ev.type==ev_mouse){
        for (int i=0; i < teglalapok.size(); i++){
            if (teglalapok[i].benne(ev.pos_x, ev.pos_y)){
                kocka=i;
                kijelolt=!kijelolt;
                std::cout <<"jaj"<<endl;
            }
        }
    }
}

void Lista::elemekbe()
{
}

void Lista::teglalapokkesz()
{
    for(int i=0; i < elemek.size(); i++){
        teglalap * teg = new teglalap(_x, _y+(gout.cascent() + gout.cdescent())*(i+1), _size_x, gout.cascent() + gout.cdescent());
        teglalapok.push_back(*teg);
    }
}