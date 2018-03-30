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
void readLimits(double &l, double &r)
{
    cout << "print left and right borders:\n";
    cin >> l >> r;
}
void readSize(int &N, double &dx)
{
    cout << "print numbers of points\n";
    cin >> N;
}

bool isReady(int function, int calculateScheme, double a, double b, double dx, int N)
{
    return true;
}

void init(vector<MathFuncton*> &functions, vector<CalculateIntegral*> &calculateSchemes)
{
    Sinus *msin = new Sinus();
    Cosinus* mcos = new Cosinus();
	LinearFuncton* mlf = new LinearFuncton();
	functions = { (MathFuncton*)msin , (MathFuncton*)mcos, (MathFuncton*)mlf };

    RightRectangleMethod *m1 = new RightRectangleMethod();
    LeftRectangleMethod *m2 = new LeftRectangleMethod();
    TrapezeMethod *m3 = new TrapezeMethod();
    Monte_KarloMethod *m4 = new Monte_KarloMethod();
	Gauss_Method *m5 = new Gauss_Method();

	calculateSchemes = { (CalculateIntegral*)m1, (CalculateIntegral*)m2, 
		(CalculateIntegral*)m3, (CalculateIntegral*)m4, (CalculateIntegral*)m5 };
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

    menu.push_back("calculate integral"); //Лучше чтобы меню было на русском, а то Эгаму будет не понятно!!!
	menu.push_back("set integral");
	menu.push_back("set function");
	menu.push_back("set limit of integration");
	menu.push_back("set num point");
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
			if (isReady(function, calculateScheme, a, b, dx, N))
			{
				cout << calculateSchemes[calculateScheme]->calculate(functions[function], a, b, N) << '\n';
			}
        }
        else if (menu.choice == "2")
        {
			readFunction(function, functions);
			readLimits(a, b);
			readScheme(calculateScheme, calculateSchemes);
			readSize(N, dx);           
        }
		else if (menu.choice == "3")
		{
			readFunction(function, functions);
		}
		else if (menu.choice == "4")
		{
			readLimits(a, b);
		}
		else if (menu.choice == "5")
		{
			readScheme(calculateScheme, calculateSchemes);
		}
		else if (menu.choice == "6")
		{
			readSize(N, dx);
		}
        else
        {
            menu.clear();
        }
    }
    return 0;
}