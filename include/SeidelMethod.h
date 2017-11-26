#pragma once
#include "CalculatingMethod.h"
class SeidelMethod : public CalculatingMethod
{
public:
	Matrix solve();
private:
	Matrix getU(Matrix &m, Matrix &x, Matrix &f) //(0 x2) * -xx1 + f1 
	{											 //(0  0) * -xx2 + f2
		int row = m.gRow();
		int col = m.gCol();
		Matrix newF(row, 1);
		for (int i = 0; i < row; i++)
		{
			newF[i][0] += f[i][0];
			for (int j = i + 1; j < col; j++)
				newF[i][0] -= m[i][j] * x[j][0];
		}
		return newF;
	}
};