#pragma once
#include <string>
#include <cmath>
using std::string;
class MathFuncton
{
protected:
    string name;
public:
    MathFuncton(){}
    virtual double operator() (double x) = 0;
    string getName()
    {
        return name;
    }
};

class Sinus : MathFuncton
{
public:
    Sinus()
    {
        name = "sinus";
    }
    double operator() (double x) override
    {
        return sin(x);
    }
};

class Cosinus : MathFuncton
{
public:
    Cosinus()
    {
        name = "cosinus";
    }
    double operator() (double x) override
    {
        return cos(x);
    }
};

class LinearFuncton : MathFuncton
{
public:
	LinearFuncton()
	{
		name = "linear functon";
	}
	double operator() (double x) override
	{
		return x;
	}
};

