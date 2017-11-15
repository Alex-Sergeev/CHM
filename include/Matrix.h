#pragma once
#include <vector>
class Matrix
{
private:
	std::vector<std::vector<double>> vv;
public:
	int gRow() const;
	int gCol() const;
	Matrix();
	Matrix(int row, int col);
	Matrix(int row, int col, double val);

	std::vector<double>& operator [] (int i);
	Matrix operator * (Matrix& m);
	Matrix operator * (double val);
	Matrix operator / (double val);
	Matrix operator + (Matrix& m);
	Matrix operator - (Matrix& m);
	//Matrix& operator = (const Matrix& m);
	double getNorm();
	void substractRow(int i, int j, double val);

	friend std::ostream& operator<<(std::ostream& os, Matrix& m);
};