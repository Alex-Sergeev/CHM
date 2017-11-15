#include "altTriang.h"
#include <algorithm>
using namespace std;

Matrix AltTriang::getR(Matrix &A)
{
	Matrix m(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		for (int j = 0; j < A.gCol() - i; j++)
			if (i != j) m[i][j] = 0.5 * m[i][j];
			else m[i][j] = m[i][j];
	return m;
}

Matrix AltTriang::getRt(Matrix &A)
{
	Matrix m(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		for (int j = 0; j <= i; j++)
			if (i != j) m[i][j] = 0.5 * m[i][j];
			else m[i][j] = m[i][j];
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
	Matrix E(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		E[i][i] = 1.0;
	B = (E + Rt*omega)*(E + R*omega);
}

Matrix AltTriang::solve()
{
	double omega, tau, xi;
	Matrix R, Rt, B, x0(A.gRow(), 1), x(A.gRow(), 1), fi(A.gRow(), 1);
	preSolve(omega, tau, xi, R, Rt, A, B);

	for (int i = 0; i < step; i++)
	{
		Matrix tmp0= B*x0, tmp1 = A*x0*tau, tmp2 = f*tau;
		fi = tmp0 - tmp1 + tmp2;
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
	return getR(A).getNorm()*getRt(A).getNorm()*4.0/A.getNorm();
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
