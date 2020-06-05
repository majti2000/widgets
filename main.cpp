#include "graphics.hpp"
#include "widgets.hpp"
#include "szambeallito.hpp"
#include "checkbox.hpp"
#include "statictext.hpp"
#include "textbox.hpp"
#include "gomb.hpp"
#include "teglalap.hpp"
#include "applikacio.hpp"
#include "lista.hpp"
#include <vector>

using namespace std;
using namespace genv;

class App : public Applikacio
{
protected:
    textbox * egy;
    textbox * ketto;
    Szambeallito * harom;
    Szambeallito * negy;
    Gomb * ot;
    Gomb * hat;
    Lista * het;
    statictext * nyolc;
public:
    App()
    {
        vector<string> elemek={"Nyuszi","Vidra","Corgi","Mumus"};
        egy = new textbox(10, 200, 150, 20);
        ketto = new textbox(10, 250, 100, 30);
        het = new Lista (50, 50, 100, 60, elemek);
        bele(egy);
        bele(ketto);
        bele(het);
        nyolc = new statictext(300,300,"VIDRA");
        bele(nyolc);
        /*harom = new Szambeallito(10, 10, 120, 30, 30, 40, 35);
        negy = new Szambeallito(10, 100, 100, 30, 10, 90, 15);
        bele(harom);
        bele(negy);*/
        ot = new Gomb (200, 100, 120, 30, [=](){ printf("Maci\n");}, "Gombi");
        bele(ot);
       // kiir();
    }
    /*void kiir(){
        egy->kival(0,0);
        ketto->kival(0,0);
    }*/
};

int main()
{
    App app;
    app.fut(400,400);
    return 0;
}
