#pragma once
#include "CalculatingMethod.h"
class AltTriang : public CalculatingMethod
{
public:
	static void preSolve(double &omega, double &tau, double &xi, Matrix &R, Matrix &Rt, Matrix &A, Matrix &B);
	Matrix solve();
	static Matrix getSolve(Matrix A, Matrix f, int numIterations);
	AltTriang(const Matrix &aa, const Matrix &ff, int max)
	{
		A = aa;
		f = ff;
		maxStep = max;
	};
protected:
	static double getGamma1(double delt, double xi);
	static double getGamma2(double delt, double Delt);
	static double getDelt(Matrix &A);
	static double getdelt(Matrix &A);
	static double getXi(double delt, double Delt);
	static double getOmega(double delt, double Delt);
	static double getTau(double gamma1, double gamma2);
	static Matrix getR(Matrix &A);
	static Matrix getRt(Matrix &A);
private:
};
