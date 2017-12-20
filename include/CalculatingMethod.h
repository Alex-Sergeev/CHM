#pragma once
#include "Matrix.h"

class CalculatingMethod
{
protected:
	Matrix A;
	Matrix f;
	Matrix x;
	int maxStep = 1000;
public:
	CalculatingMethod() {};
	CalculatingMethod(const Matrix &aa, const Matrix &ff, const Matrix &xx, int max) :A(aa), f(ff), maxStep(max){};
	CalculatingMethod(const Matrix &aa, const Matrix &ff) : A(aa), f(ff){};
	void setA(const Matrix &a);
	void setF(const Matrix &f);
	void setX(const Matrix &x);

	Matrix& getA();
	Matrix& getF();
	Matrix& getX();

	//virtual bool isReady();
	//virtual void print();
};