#pragma once
#include "CalculatingMethod.h"
class AltTriang : public CalculatingMethod
{
public:
	void preSolve(double &omega, double &tau, double &xi, Matrix &R, Matrix &Rt, Matrix &A, Matrix &B);
	Matrix solve();
	Matrix solve(const Matrix &aa, const Matrix &ff, const Matrix &xx, int max);
	AltTriang(const Matrix &aa, const Matrix &ff, int max)
	{
		A = aa;
		f = ff;
		maxStep = max;
	};
protected:
	double getGamma1(double delt, double xi);
	double getGamma2(double delt, double Delt);
	double getDelt(Matrix &A);
	double getdelt(Matrix &A);
	double getXi(double delt, double Delt);
	double getOmega(double delt, double Delt);
	double getTau(double gamma1, double gamma2);
	Matrix getR(Matrix &A);
	Matrix getRt(Matrix &A);
private:
};
