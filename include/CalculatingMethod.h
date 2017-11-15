#pragma once
#include "Matrix.h"

class calculatingMethod
{
private:
	Matrix A;
	Matrix f;
	Matrix x;
	double accuracy;
	int step;
public:
	void setA(const Matrix &a);
	void setF(const Matrix &f);
	void setX(const Matrix &x);
	void setStep(int step);
	void setAccuracy(double accuracy);

	Matrix& getA();
	Matrix& getF();
	Matrix& getX();
	int getStep(); const
	double getAccuracy(); const

	virtual bool isReady() = 0;
};