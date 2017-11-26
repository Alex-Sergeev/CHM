#include "Matrix.h"
#include "altTriang.h"
#include <iostream>

char *read = "in.txt", *write = "out.txt";

int main()
{
	Matrix A(2,2), f(2,1);
	double coef = 10.0;
	A[0][0] = 0.2;
	A[0][1] = 0.1;
	A[1][0] = 0.1;
	A[1][1] = 0.2;
	f[0][0] = 0.1;
	f[1][0] = -0.1;
	AltTriang sys(A*coef, f*coef, 5);
	std::cout<<sys.solve();
	return 0;
}