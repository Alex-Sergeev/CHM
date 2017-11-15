#pragma once
#include "Matrix.h"

class CalculatingMethod
{
protected:
	Matrix A;
	Matrix f;
	Matrix x;
	double accuracy;
	int step = 0;
	int maxStep = 1000;
public:
	CalculatingMethod() {};
	CalculatingMethod(const Matrix &aa, const Matrix &ff, const Matrix &xx, int max) :A(aa), f(ff), maxStep(max){};
	CalculatingMethod(const Matrix &aa, const Matrix &ff, double aacuracy) : A(aa), f(ff), accuracy(aacuracy){};
	void setA(const Matrix &a);
	void setF(const Matrix &f);
	void setX(const Matrix &x);
	void setStep(int step);
	void setAccuracy(double accuracy);

	Matrix& getA();
	Matrix& getF();
	Matrix& getX();
	int getStep() const;
	double getAccuracy() const;

	//virtual bool isReady();
	virtual Matrix solve() = 0;
	//virtual void print();
};