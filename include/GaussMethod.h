#pragma once
#include "CalculatingMethod.h"
class GaussMethod : public CalculatingMethod
{
public:
	Matrix solve();
	void static setTriangle(Matrix &A, Matrix &f);
	Matrix static getSolve(Matrix &A, Matrix &f);
	Matrix static getSolveT(Matrix &A, Matrix &f);
};