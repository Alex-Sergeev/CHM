#include "CalculatingMethod.h"

void calculatingMethod::setA(const Matrix& a)
{
	A = a;
}

void calculatingMethod::setF(const Matrix & f)
{
	this->f = f;
}

void calculatingMethod::setX(const Matrix & x)
{
	this->x = x;
}

void calculatingMethod::setStep(int step)
{
	this->step = step;
}

void calculatingMethod::setAccuracy(double accuracy)
{
	this->accuracy = accuracy;
}

Matrix & calculatingMethod::getA()
{
	return A;
}

Matrix & calculatingMethod::getF()
{
	return f;
}

Matrix & calculatingMethod::getX()
{
	return x;
}

int calculatingMethod::getStep()
{
	return step;
}

const double calculatingMethod::getAccuracy()
{
	return accuracy;
}
