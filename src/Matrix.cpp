#include "Matrix.h"
#include <iostream>
using namespace std;

int Matrix::gRow() const
{
	return vv.size();
}

int Matrix::gCol() const
{
	if (gRow() == 0)
		return 0;
	return vv[0].size();
}

Matrix::Matrix()
{
	vv = vector<vector<double>>();
}

Matrix::Matrix(int row, int col)
{
	vv = vector<vector<double>>(row);
	for (int i = 0; i < row; i++)
		vv[i] = vector<double>(col);
}

Matrix::Matrix(int row, int col, double val): Matrix(row, col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			vv[i][j] = val;
}

std::vector<double>& Matrix::operator[](int i)
{
	return vv[i];
}

Matrix Matrix::operator*(Matrix &m)
{
	if (gCol() != m.gRow()) return Matrix();
	Matrix newMatr(gRow(), m.gCol());
	for (int z = 0; z < m.gCol(); z++)
		for (int i = 0; i < gRow(); i++)
			for (int j = 0; j < m.gRow(); j++)
				newMatr[z][i] += vv[z][j] * m[j][i];
	return newMatr;
}

/*Matrix & Matrix::operator=(const Matrix & m)
{
	if (&m == this) return *this;
	this->vv.clear();
	vv = vector<vector<double>>(m.vv);
	return *this;
}*/

std::ostream & operator<<(std::ostream & os, Matrix & m)
{
	if (m.gRow() == 0) os << 0;
	for (int i = 0; i < m.gRow(); i++)
	{
		for (int j = 0; j < m.gCol(); j++)
			os << m[i][j] << ' ';
		os << '\n';
	}
	return os;
}
