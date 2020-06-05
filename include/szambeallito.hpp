#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "teglalap.hpp"

using namespace std;


class Szambeallito : public Widget {
protected:
    int ertek;
    teglalap also, felso;
    int alhat, fenhat;
public:
    Szambeallito(int x, int y, int szelesseg, int magassag, int al, int fel, int ertekaminemszamit);
    virtual void draw() ;
    virtual void handle(genv::event ev);
};

#endif 