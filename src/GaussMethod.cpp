#include "GaussMethod.h"
Matrix GaussMethod::solve()
{
	Matrix tmpA = A, tmpF = f;
	setTriangle(tmpA, tmpF);
	return getSolve(tmpA, tmpF);
}

// x x x 
// 0 x x
// 0 0 x
void GaussMethod::setTriangle(Matrix &A, Matrix &f)
{
	for (int i = 0; i < A.gRow() - 1; i++)
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
			double coef = A[j][i] / A[i][i];
			A.substractRow(i, j, i, coef);
			f.substractRow(0, j, i, coef);
		}
	}
}
// x x x 
// 0 x x
// 0 0 x
Matrix GaussMethod::getSolve(Matrix &A, Matrix & f)
{
	Matrix ans(A.gRow(), 1);
	for (int i = A.gRow() - 1; i >= 0; i--)
	{
		double tmp = f[i][0];
		for (int j = i + 1; j < A.gRow(); j++)
			tmp -= A[i][j] * ans[j][0];
		ans[i][0] = tmp / A[i][i];
	}
	return ans;
}
// x 0 0
// x x 0
// x x x
Matrix GaussMethod::getSolveT(Matrix & A, Matrix & f)
{
	Matrix ans(A.gRow(), 1);
	for (int i = 0; i < A.gRow();i++)
	{
		double tmp = f[i][0];
		for (int j = 0; j < i; j++)
			tmp -= A[i][j] * ans[j][0];
		ans[i][0] = tmp / A[i][i];
	}
	return ans;
}
