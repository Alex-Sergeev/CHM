#pragma once
#include <string>
#include "math_function.h"
class CalculateIntegral
{
protected:
    std::string name;
    int numPoints;
public:
    virtual double calculate(MathFuncton &f, double a, double b, int numPoints) = 0;
    virtual double calculate(MathFuncton &f, double a, double b, double dx) = 0;
};

class RightRectangleMethod : CalculateIntegral
{
    RightRectangleMethod()
    {
        name = "right rectangle method";
    }
    double calculate(MathFuncton &f, double a, double b, int numPoints) override
    {
        double dx = (b - a) / (numPoints - 1);
        return calculate(f, a, b, dx);
    }

    double calculate(MathFuncton &f, double a, double b, double dx) override
    {
        double res = 0;
        int numPoints = (b - a) / dx + 0.5;
        double x = a + dx;
        for (int i = 0; i < numPoints; i++)
        {
            res += f(x)*dx;
            x += dx;
        }
        return res;
    }
};


class LeftRectangleMethod : CalculateIntegral
{
    LeftRectangleMethod()
    {
        name = "left rectangle method";
    }
    double calculate(MathFuncton &f, double a, double b, int numPoints) override
    {
        double dx = (b - a) / (numPoints - 1);
        return calculate(f, a, b, dx);
    }

    double calculate(MathFuncton &f, double a, double b, double dx) override
    {
        double res = 0;
        int numPoints = (b - a) / dx + 0.5;
        double x = a;
        for (int i = 0; i < numPoints; i++)
        {
            res += f(x)*dx;
            x += dx;
        }
        return res;
    }
};