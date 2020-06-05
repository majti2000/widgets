#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "teglalap.hpp"
#include <string>
#include <vector>
 
class Lista : public Widget
{
protected:
    std::vector<std::string> elemek;
    std::vector<teglalap> teglalapok;
    bool kijelolt;
    int kocka;
public:
    Lista(int x, int y, int sx, int sy, std::vector<std::string> elemek);
    virtual void handle(genv::event ev);
    virtual void draw();
    void elemekbe(); 
    void teglalapokkesz();
};

#endif