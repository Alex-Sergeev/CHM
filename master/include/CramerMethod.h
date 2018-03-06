#pragma once
#include "CalculatingMethod.h"
class CramerMethod : public CalculatingMethod
{
public:
	Matrix static getSolve(Matrix A, Matrix f);
	static double getDeterminant(Matrix A);
};