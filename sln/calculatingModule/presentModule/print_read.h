#pragma once
#include <Matrix.h>
#include <iostream>
#include <fstream>
#include <iostream>
void openRead(char *file, std::ifstream &is)
{
	is = std::ifstream(file);
}
void ReadSystem(std::ifstream &is, Matrix &A, Matrix &f)
{
	int n;
	is >> n;
	A.read(n, n, is);
	f.read(n, 1, is);
}
void ReadParam(std::ifstream &is, int& curRep, double& curAccuracy, int& maxRep, double& needAccuracy)
{
	is >> curRep >> curAccuracy >> maxRep >> needAccuracy;
}