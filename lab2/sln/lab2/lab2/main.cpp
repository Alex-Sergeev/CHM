#include "menu.h"
#include "math_function.h"
#include "calculate_integral.h"
using namespace std;

struct CalculateInfo
{
	vector<MathFuncton*> functions;
	vector<CalculateIntegral*> calculateSchemes;

	int function;
	int calculateScheme;
	double a, b;
	double dx;
	int N;

	double calculate()
	{
		return calculateSchemes[calculateScheme]->calculate(functions[function], a, b, N);
	}
};

void printFunctions(const CalculateInfo &calculateInfo)
{
    for (int i = 0; i < calculateInfo.functions.size(); i++)
    {
        cout << i << ' ' << calculateInfo.functions[i]->getName()<<'\n';
    }
}
void printCalculateSchemes(const CalculateInfo &calculateInfo)
{
    for (int i = 0; i < calculateInfo.calculateSchemes.size(); i++)
    {
        cout << i << ' ' << calculateInfo.calculateSchemes[i]->getName() << '\n';
    }
}
void readFunction(CalculateInfo &calculateInfo)
{
    cout << "Choice the function:\n";
    printFunctions(calculateInfo);
    cin >> calculateInfo.function;
}
void readScheme(CalculateInfo &calculateInfo)
{
    cout << "Choice the calculate scheme:\n";
    printCalculateSchemes(calculateInfo);
    cin >> calculateInfo.calculateScheme;
}
void readLimits(CalculateInfo &calculateInfo)
{
    cout << "print left and right borders:\n";
    cin >> calculateInfo.a >> calculateInfo.b;
}
void readSize(CalculateInfo &calculateInfo)
{
    cout << "print numbers of points\n";
    cin >> calculateInfo.N;
}

bool isReady(CalculateInfo &calculateInfo)
{
    return true;
}

void init(CalculateInfo &calculateInfo)
{
    Sinus *msin = new Sinus();
    Cosinus* mcos = new Cosinus();
	LinearFuncton* mlf = new LinearFuncton();
	calculateInfo.functions = { (MathFuncton*)msin , (MathFuncton*)mcos, (MathFuncton*)mlf };

    RightRectangleMethod *m1 = new RightRectangleMethod();
    LeftRectangleMethod *m2 = new LeftRectangleMethod();
    TrapezeMethod *m3 = new TrapezeMethod();
    Monte_KarloMethod *m4 = new Monte_KarloMethod();
	Gauss_Method *m5 = new Gauss_Method();

	calculateInfo.calculateSchemes = { (CalculateIntegral*)m1, (CalculateIntegral*)m2,
		(CalculateIntegral*)m3, (CalculateIntegral*)m4, (CalculateIntegral*)m5 };
}

int main()
{
    Menu menu;
	CalculateInfo calculateInfo;

    init(calculateInfo);

    menu.push_back("calculate integral"); //Лучше чтобы меню было на русском, а то Эгаму будет не понятно!!!
	menu.push_back("set integral");
	menu.push_back("set function");
	menu.push_back("set limit of integration");
	menu.push_back("set scheme");
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
			if (isReady(calculateInfo))
			{
				menu.clear();
				cout << calculateInfo.calculate() << '\n';
			}
        }
        else if (menu.choice == "2")
        {
			readFunction(calculateInfo);
			readLimits(calculateInfo);
			readScheme(calculateInfo);
			readSize(calculateInfo);
        }
		else if (menu.choice == "3")
		{
			readFunction(calculateInfo);
		}
		else if (menu.choice == "4")
		{
			readLimits(calculateInfo);
		}
		else if (menu.choice == "5")
		{
			readScheme(calculateInfo);
		}
		else if (menu.choice == "6")
		{
			readSize(calculateInfo);
		}
        else
        {
            menu.clear();
        }
    }
    return 0;
}