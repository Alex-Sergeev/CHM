#include "calculatingMethod.h"

void CalculatingMethod::setA(const Matrix& a)
{
	A = a;
}

void CalculatingMethod::setF(const Matrix & f)
{
	this->f = f;
}

void CalculatingMethod::setX(const Matrix & x)
{
	this->x = x;
}

Matrix & CalculatingMethod::getA()
{
	return A;
}

Matrix & CalculatingMethod::getF()
{
	return f;
}

Matrix & CalculatingMethod::getX()
{
	return x;
}
