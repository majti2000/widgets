#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "widgets.hpp"
#include "graphics.hpp"

class CheckBox : public Widget {
protected:
    bool checked;
public:
    CheckBox(int x, int y, int wx, int hy);
    virtual void handle(genv::event ev);
    virtual void draw();
    virtual bool checked_e();
};

#endif 
