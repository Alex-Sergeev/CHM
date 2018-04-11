#pragma once
#include <string>
#include "math_function.h"

int rounding(double x)
{
    return x + 0.5;
}

class CalculateIntegral
{
protected:
    std::string name;


public:
    virtual double calculate(MathFuncton *f, double a, double b, int numPoints) = 0;
    virtual double calculate(MathFuncton *f, double a, double b, double dx) = 0;
    string getName()
    {
        return name;
    }
};

class RightRectangleMethod : CalculateIntegral
{
public:
    RightRectangleMethod()
    {
        name = "right rectangle method";
    }
    double calculate(MathFuncton *f, double a, double b, int numPoints) override
    {
        double dx = (b - a) / (numPoints - 1);
        return calculate(f, a, b, dx);
    }

    double calculate(MathFuncton *f, double a, double b, double dx) override
    {
        double res = 0;
        int numPoints = rounding((b - a) / dx); //+0.5 серьёзно? - это для правильного округления
        double x = a + dx;
        for (int i = 0; i < numPoints; i++)
        {
            res += (*f)(x)*dx;
            x += dx;
        }
        return res;
    }
};


class LeftRectangleMethod : CalculateIntegral
{
public:
    LeftRectangleMethod()
    {
        name = "left rectangle method"; 
    }
    double calculate(MathFuncton *f, double a, double b, int numPoints) override
    {
        double dx = (b - a) / (numPoints - 1);
        return calculate(f, a, b, dx);
    }

    double calculate(MathFuncton *f, double a, double b, double dx) override
    {
        double res = 0;
        int numPoints = rounding((b - a) / dx);
        double x = a;
        for (int i = 0; i < numPoints; i++)
        {
            res += (*f)(x)*dx;
            x += dx;
        }
        return res;
    }
};

class TrapezeMethod : CalculateIntegral
{
public:
	TrapezeMethod()
	{
		name = "trapeze method";
	}
	double calculate(MathFuncton *f, double a, double b, int numPoints) override
	{
		double dx = (b - a) / (numPoints - 1);
		return calculate(f, a , b, dx);
	}

	double calculate(MathFuncton *f, double a, double b, double dx) override
	{
		double res = 0;
		int numPoints = rounding((b - a) / dx);
		double x = a;
		for (int i = 0; i < numPoints; i++)
		{
			res += ((*f)(x + dx) + (*f)(x)) / 2 * dx; //f(x.i+1)+f(x.i)/2 * (x.i+1 - x.i) Формула метода трапеций С Википедии
			x += dx;
		}
		return res;
	}
};

class Monte_KarloMethod : CalculateIntegral
{
public:
	Monte_KarloMethod()
	{
		name = "monte karlo method";
	}
	double calculate(MathFuncton *f, double a, double b, int numPoints) override
	{
		double dx = (b - a) / (numPoints - 1);
		return calculate(f, a, b, dx);
	}

	double calculate(MathFuncton *f, double a, double b, double dx) override
	{
		double res = 0;
		int numPoints = rounding((b - a) / dx);
		double x = a;
		for (int i = 0; i < numPoints; i++)
		{
			res += (*f)(x);
			x += dx;
		}
		res *=(b - a) / numPoints;
		return res;
	}
};

class Gauss_Method : CalculateIntegral
{
public:
	Gauss_Method()
	{
		name = "gauss method";
	}
	double calculate(MathFuncton *f, double a, double b, int numPoints) override
	{
		double dx = (b - a) / (numPoints - 1);
		return calculate(f, a, b, dx);
	}

	double calculate(MathFuncton *f, double a, double b, double dx) override
	{
		double res = 0;
		int numPoints = rounding((b - a) / dx);
		double x = a;

		for (int i = 0; i < numPoints; i++)
		{
			res += dx / 2 * ((*f)(((x + x + dx) / 2) - dx / 2 * sqrt(3)) + (*f)(((x + x + dx) / 2) + dx / 2 * sqrt(3)));
			x += dx;
		}
		return res;
	}
};

class Simpson_Method : CalculateIntegral
{
public:
    Simpson_Method()
    {
        name = "simpson_Method";
    }
    double calculate(MathFuncton *f, double a, double b, int numPoints) override
    {
        double res = 0.0;
        double h = (b - a) / numPoints;
        double x1 = a, x2 = a + h, x3 = a + 2*h;
        for (int i = 0; i < numPoints - 1; i+= 2)
        {           
            res += (*f)(x1);
            res += 4.0*(*f)(x2);
            res += (*f)(x3);

            x1 += 2*h;
            x2 += 2*h;
            x3 += 2*h;
        }
        return res * h / 3.0;
    }
    double calculate(MathFuncton *f, double a, double b, double dx) override
    {
        return 0.0;
    }
};