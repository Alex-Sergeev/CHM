#include "menu.h"
#include "math_function.h"
using namespace std;

vector<MathFuncton*> functions;

int main()
{
    Menu menu;
    menu.push_back("set integral");
    menu.push_back("calculate integral"); //Ћучше чтобы меню было на русском, а то Ёгаму будет не пон€тно!!!
    while (1)
    {
        menu.print();
        cin >> menu.choice;
        if (menu.choice == menu.exit)
        {
            break;
        }
        else
        {
            menu.clear();
        }
    }
    return 0;
}