#pragma once
#include <Matrix.h>
#include <iostream>
void ReadSystem(std::iostream &is, Matrix &A, Matrix &f)
{
	int n;
	is >> n;
	A.read(n, n, is);
	f.read(n, 1, is);
}
void ReadParam(std::iostream &is, int& curRep, double& curAccuracy, int& maxRep, double& needAccuracy)
{
	is >> curRep >> curAccuracy >> maxRep >> needAccuracy;
}