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
	double getNorm();
	void substractRow(int start, int i, int j, double val);
	void swapRow(int i, int j);
	static Matrix createE(int i);
	void read(int n, int m, std::istream& is);

	friend std::ostream& operator<<(std::ostream& os, Matrix& m);
	friend std::istream& operator>>(std::istream& is, Matrix& m);
};