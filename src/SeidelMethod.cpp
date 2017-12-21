#include "..\include\SeidelMethod.h"
#include "GaussMethod.h"

Matrix SeidelMethod::solve(int numIter)
{
	return getSolve(A, f, maxStep);
}

Matrix SeidelMethod::getSolve(Matrix A, Matrix f, int numIteration)
{
	Matrix x0(f.gRow(), 1), x1(f.gRow(), 1), f1 = f;
	for (int i = 0; i < numIteration; i++)
	{
		f1 = getF(A, x0, f);
		x1 = GaussMethod::solveTriangleT(A, f1);
		x0 = x1;
	}
	return x1;
}
