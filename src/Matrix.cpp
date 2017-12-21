#include "Matrix.h"
#include <algorithm>
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
	for (int z = 0; z < gRow(); z++)
		for (int i = 0; i < m.gCol(); i++)
			for (int j = 0; j < m.gRow(); j++)
				newMatr[z][i] += vv[z][j] * m[j][i];
	return newMatr;
}

Matrix Matrix::operator*(double val)
{
	Matrix m(gRow(), gCol());
	for (int i = 0; i < gRow(); i++)
		for (int j = 0; j < gCol(); j++)
			m.vv[i][j] = vv[i][j] * val;
	return m;
}

Matrix Matrix::operator/(double val)
{
	Matrix m(gRow(), gCol());
	for (int i = 0; i < gRow(); i++)
		for (int j = 0; j < gCol(); j++)
			m.vv[i][j] = vv[i][j] / val;
	return m;
}

Matrix Matrix::operator+(Matrix & m)
{
	Matrix ans(gRow(), gCol());
	for (int i = 0; i < gRow(); i++)
		for (int j = 0; j < gCol(); j++)
			ans.vv[i][j] = vv[i][j] + m.vv[i][j];
	return ans;
}

Matrix Matrix::operator-(Matrix & m)
{
	Matrix ans(gRow(), gCol());
	for (int i = 0; i < gRow(); i++)
		for (int j = 0; j < gCol(); j++)
			ans.vv[i][j] = vv[i][j] - m.vv[i][j];
	return ans;
}

/*double& Matrix::vec(int i)
{
	return vv[i][0];
}*/

double Matrix::getNorm()
{
	double ans = 0.0;
	for (int i = 0; i < gRow(); i++)
	{
		double tmp = 0.0;
		for (int j = 0; j < gCol(); j++)
			tmp += abs(vv[i][j]);
		ans = max(tmp, ans);
	}
	return ans;
}

void Matrix::substractRow(int start, int i, int j, double val)
{
	for (int z = start; z < gCol(); z++)
		vv[i][z] -= vv[j][z] * val;
}

void Matrix::swapRow(int i, int j)
{
	std::swap(vv[i], vv[j]);
}

Matrix Matrix::createE(int i)
{
	Matrix E(i, i);
	for (int i = 0; i < E.gRow(); i++)
		E[i][i] = 1.0;
	return E;
}

Matrix Matrix::createDiagDominMatrix(int n, int min, int max)
{
	Matrix m(n, n);
	srand(0);
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (j != i)
			{
				int el = rand() % (max - min + 1) + min;
				m[i][j] = el;
				sum += abs(el);
			}
		m[i][i] = sum + rand() % (max - min + 1);
	}
	return m;
}

Matrix Matrix::createVector(int n, int min, int max)
{
	Matrix vec(n, 1);
	srand(0);
	for (int i = 0; i < n; i++)
	{
		int el = rand() % (max - min + 1) + min;
		vec[i][0] = el;
	}
	return vec;
}

Matrix Matrix::createSimmetricMatrix(int n, int min, int max)
{
	Matrix m(n, n);
	srand(0);
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (j != i)
			{
				int el = rand() % (max - min + 1) + min;
				m[i][j] = el;
				sum += abs(el);
			}
		m[i][i] = sum + rand() % (max - min + 1);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			m[i][j] = m[j][i];
	}
	return m;
}

void Matrix::read(int n, int m, std::istream& is)
{
	vv = vector<vector<double>>(n);
	for (int i = 0; i < n; i++)
		vv[i] = vector<double>(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			is >> vv[i][j];
}

std::ostream & operator<<(std::ostream & os, Matrix & m)
{
	if (m.gRow() == 0) os << 0;
	if (m.gCol() != 1)
	{
		for (int i = 0; i < m.gRow(); i++)
		{
			for (int j = 0; j < m.gCol(); j++)
				os << m[i][j] << ' ';
			os << '\n';
		}
	}
	else
	{
		for (int j = 0; j < m.gRow(); j++)
			os << m[j][0] << ' ';
	}
	os << '\n';
	return os;
}

std::istream & operator >> (std::istream & is, Matrix & m)
{
	for (int i = 0; i < m.gRow(); i++)
		for (int j = 0; j < m.gCol(); j++)
			is >> m[i][j];
	return is;
}
