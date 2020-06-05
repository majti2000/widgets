#include "applikacio.hpp"
#include "widgets.hpp"

using namespace std;
using namespace genv;

void Applikacio::handle()
{
    for (Widget *widgs : widgets){
        widgs->draw();
    }
    gout << refresh;

    event ev;

    int kp=-1;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if (ev.type==ev_mouse && ev.button==btn_left)
        {
            for (int i=0; i < widgets.size(); i++) 
            {
                if (widgets[i]->kival(ev.pos_x, ev.pos_y)){
                        kp=i;
                }
            }
        }
        
        if (kp!=-1){
            widgets[kp]->handle(ev);
        }

        for (Widget *wid : widgets){
            wid->draw();
        }
        gout << refresh;
    }
}

void Applikacio::fut(int a, int b)
{
    genv::gout.open(a,b);
    handle();
}

void Applikacio::bele(Widget * w){
    widgets.push_back(w);
}