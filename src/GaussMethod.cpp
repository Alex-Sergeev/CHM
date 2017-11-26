#include "GaussMethod.h"

Matrix GaussMethod::solve()
{
	return Matrix();
}

Matrix GaussMethod::getTriangle(Matrix &A, Matrix &f)
{
	for (int i = 0; i < A.gRow(); i++)
	{
		double max = A[i][i];
		for (int j = i + 1; j < A.gRow(); j++)
			if (A[j][i] > max)
			{
				max = A[j][i];
				std::swap(A[i], A[j]);
				std::swap(f[i][0], f[j][0]);
			}
		if (max == 0)
			throw "bad matix";
		for (int j = i + 1; j < A.gRow(); j++)
		{
			A.substractRow(i, i, j, A[j][i] / A[i][i]);
			f.substractRow(0, i, j, f[j][0] / f[i][0]);
		}
	}
	return Matrix();
}

Matrix GaussMethod::getSolve(Matrix & A, Matrix & f)
{
	Matrix ans(A.gRow(), 1);
	for (int i = A.gRow() - 1; i >= 0; i--)
	{
		double tmp = f[i][0];
		for (int j = i; j < A.gRow(); j++)
		{
			tmp -= A[i][j] * ans[j][0];
		}
		ans[i][0] = tmp / A[i][i];
	}
	return ans;
}

Matrix GaussMethod::getSolveT(Matrix & A, Matrix & f)
{
	Matrix ans(A.gRow(), 1);
	for (int i = 0; i < A.gRow();i++)
	{
		double tmp = f[i][0];
		for (int j = 0; j < i; j++)
		{
			tmp -= A[i][j] * ans[j][0];
		}
		ans[i][0] = tmp / A[i][i];
	}
	return ans;
}
