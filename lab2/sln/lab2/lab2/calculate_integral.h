#pragma once
#include <string>
class CalculateIntegral
{
    std::string name;
    virtual double calculate(double a, double b) = 0;
};