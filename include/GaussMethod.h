#pragma once
#include "CalculatingMethod.h"
class GaussMethod : public CalculatingMethod
{
public:
	Matrix static getSolve(Matrix &A, Matrix &f);
	Matrix static getSolveT(Matrix &A, Matrix &f);
};