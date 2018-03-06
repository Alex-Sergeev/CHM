#pragma once
#include "CalculatingMethod.h"
class GaussMethod : public CalculatingMethod
{
public:
	Matrix solve();
	int static setTriangle(Matrix &A, Matrix &f);
	int static setTriangle(Matrix &A);
	Matrix static solveTriangle(Matrix A, Matrix f);
	Matrix static solveTriangleT(Matrix A, Matrix f);
	Matrix static getSolve(Matrix A, Matrix f);
};