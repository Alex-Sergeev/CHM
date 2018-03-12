#include "menu.h"
#include "math_function.h"
#include "calculate_integral.h"
using namespace std;

void printFunctions(const vector<MathFuncton*> &functions)
{
    for (int i = 0; i < functions.size(); i++)
    {
        cout << i << ' ' << functions[i]->getName()<<'\n';
    }
}
void printCalculateSchemes(const vector<CalculateIntegral*> &calculateSchemes)
{
    for (int i = 0; i < calculateSchemes.size(); i++)
    {
        cout << i << ' ' << calculateSchemes[i]->getName() << '\n';
    }
}
void readFunction(int &f, const vector<MathFuncton*> &functions)
{
    cout << "Choice the function:\n";
    printFunctions(functions);
    cin >> f;
}
void readScheme(int &scheme, const vector<CalculateIntegral*> &calculateSchemes)
{
    cout << "Choice the calculate scheme:\n";
    printCalculateSchemes(calculateSchemes);
    cin >> scheme;
}
void readBorders(double &l, double &r)
{
    cout << "print left and right borders:\n";
    cin >> l >> r;
}
void readSize(int &N, double &dx)
{
    cout << "print nubers of points\n";
    cin >> N;
}

bool isReady(int function, int calculateScheme, double a, double b, double dx, int N)
{
    return true;
}

void init(vector<MathFuncton*> &functions, vector<CalculateIntegral*> &calculateSchemes)
{
    Sinus *msin = new Sinus();
    Cosinus* mcos = new Cosinus;
    functions.push_back((MathFuncton*)msin);
    functions.push_back((MathFuncton*)mcos);

    RightRectangleMethod *rectM = new RightRectangleMethod();

    calculateSchemes.push_back((CalculateIntegral*)rectM);
}

int main()
{
    Menu menu;
    vector<MathFuncton*> functions;
    vector<CalculateIntegral*> calculateSchemes;

    int function;
    int calculateScheme;
    double a, b;
    double dx;
    int N;

    init(functions, calculateSchemes);

    menu.push_back("set integral");
    menu.push_back("calculate integral"); //Лучше чтобы меню было на русском, а то Эгаму будет не понятно!!!
    while (1)
    {
        menu.print();
        cin >> menu.choice;
        if (menu.choice == menu.exit)
        {
            break;
        }
        else if (menu.choice == "1")
        {
            readFunction(function, functions);
            readBorders(a, b);
            readScheme(calculateScheme, calculateSchemes);
            readSize(N, dx);
        }
        else if (menu.choice == "2")
        {
            if (isReady(function, calculateScheme, a, b, dx, N))
            {
                cout << calculateSchemes[calculateScheme]->calculate(functions[function], a, b, N)<<'\n';
            }
        }
        else
        {
            menu.clear();
        }
    }
    return 0;
}