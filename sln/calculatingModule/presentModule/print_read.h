#pragma once
#include <Matrix.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
string menu = "1)generate new system\n2)read new system\n3)solve system\n4)set symmetric matrix\n0)exit\n";
void openRead(char *file, std::ifstream &is)
{
	is.close();
	is = std::ifstream(file);
}
void openWrite(string s, ofstream &of)
{
	of.close();
	of.open(s);
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
string getDate()
{
	time_t t;
	struct tm * timeinfo;
	char buffer[80];
	time(&t);
	timeinfo = localtime(&t);
	strftime(buffer, 80, "day%j-time%I-%M-%S", timeinfo);
	string s(buffer);
	s += ".txt";
	return s;
}
