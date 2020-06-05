#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class statictext : public Widget{
protected:
    std::string szov;
public:
    statictext(int x, int y, std::string szov);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif 