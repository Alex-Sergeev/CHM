#include "CramerMethod.h"
#include "GaussMethod.h"
Matrix prepareMatrix(Matrix &A, Matrix &f, int i) 
{
	Matrix tmp(A);
	for (int j = 0; j < A.gRow(); j++)
		tmp[j][i] = f[j][0];
	return tmp;
}

Matrix CramerMethod::getSolve(Matrix A, Matrix f)
{
	Matrix x(A.gRow(), 1);
	double det = getDeterminant(A);
	if (det != 0.0)
		for (int i = 0; i < A.gRow(); i++)
		{
			Matrix tmp = prepareMatrix(A, f, i);
			x[i][0] = getDeterminant(tmp) / det;
		}
	return x;
}

double CramerMethod::getDeterminant(Matrix A)
{
	Matrix f(A.gRow(), 1);
	double det = 1.0;
	try
	{
		det *= GaussMethod::setTriangle(A, f);
	}
	catch (char * error)
	{
		return 0.0;
	}
	for (int i = 0; i < A.gRow(); i++)
		det *= A[i][i];
	return det;
}
