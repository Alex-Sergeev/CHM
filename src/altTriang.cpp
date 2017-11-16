#include "altTriang.h"
#include "GaussMethod.h"
#include <algorithm>
using namespace std;

Matrix AltTriang::getR(Matrix &A)
{
	Matrix m(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		for (int j = i; j < A.gCol(); j++)
			if (i == j) m[i][j] = 0.5 * A[i][j];
			else m[i][j] = A[i][j];
	return m;
}

Matrix AltTriang::getRt(Matrix &A)
{
	Matrix m(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		for (int j = 0; j <= i; j++)
			if (i == j) m[i][j] = 0.5 * A[i][j];
			else m[i][j] = A[i][j];
	return m;
}

void AltTriang::preSolve(double &omega, double &tau, double &xi, Matrix &R, Matrix &Rt, Matrix &A, Matrix &B)
{
	double delt = getdelt(A);
	double Delt = getDelt(A);
	omega = getOmega(delt, Delt);
	xi = getXi(delt, Delt);
	double g1 = getGamma1(delt, xi), g2 = getGamma2(delt, Delt);
	tau = getTau(g1, g2);
	R = getR(A);
	Rt = getRt(A);
	Matrix E = Matrix::createE(A.gRow());
	B = (E + Rt*omega)*(E + R*omega);
}

Matrix AltTriang::solve()
{
	double omega, tau, xi;
	Matrix R, Rt, B, x(A.gRow(), 1), fi, xHalf;
	preSolve(omega, tau, xi, R, Rt, A, B);
	Matrix E = Matrix::createE(A.gRow());
	Matrix tmp2 = f*tau;
	Matrix halfX = (E + Rt*omega);
	Matrix fullX = (E + R*omega);
	for (int i = 0; i < maxStep; i++)
	{
		Matrix tmp0= B*x, tmp1 = A*x*tau;
		fi = tmp0 - tmp1 + tmp2;
		//solve1
		xHalf = GaussMethod::getSolveT(halfX, fi);
		//solve2
		x = GaussMethod::getSolve(fullX, xHalf);
	}
	return x;
}

double AltTriang::getGamma1(double delt, double xi)
{
	return delt / (2.0 + 2.0 * sqrt(xi));
}

double AltTriang::getGamma2(double delt, double Delt)
{
	return sqrt(delt*Delt)/4.0;
}
double AltTriang::getDelt(Matrix & A)
{
	return (getR(A)*getRt(A)).getNorm()*4.0/A.getNorm();
}
double AltTriang::getdelt(Matrix & A)
{
	return A.getNorm();
}
double AltTriang::getXi(double delt, double Delt)
{
	return delt/Delt;
}

double AltTriang::getOmega(double delt, double Delt)
{
	return 2.0/sqrt(delt*Delt);
}

double AltTriang::getTau(double gamma1, double gamma2)
{
	return 2.0/(gamma1 + gamma2);
}
