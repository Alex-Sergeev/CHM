#pragma once
#include "CalculatingMethod.h"
class AltTriang : public CalculatingMethod
{
protected:
	Matrix B;
	double Delt;
	double delt;
public:
	//bool isReady();
	Matrix getR();
	Matrix getRt();
	
	void setDelt(double Delt);
	void setdelt(double delt);
	Matrix solve();
private:

};
