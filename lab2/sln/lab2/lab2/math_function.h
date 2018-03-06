#pragma once
#include <string>
class MathFuncton
{
    std::string name;
    virtual double operator() (double x) = 0;
};