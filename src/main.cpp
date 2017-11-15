#include "Matrix.h"
#include "altTriang.h"
#include <iostream>
using  namespace std;
void testMatrix()
{
	Matrix m(2, 2);
	m[1][1] = 1;
	cout << m[1][1] << '\n';
	Matrix a;
	a = m;
	m[1][1] = 2;
	cout << a << m;
	Matrix a1(3, 1, 1.0), a2(1, 3, 1.0),a3(2,1), a4(2,2);
	cout << a1*a2 << a2*a1;
	Matrix A(3, 2), B(2, 3);
	A[0][0] = -1;
	A[0][1] = 1;
	A[1][0] = 2;
	A[1][1] = 0;
	A[2][0] = 0;
	A[2][1] = 3;

	B[0][0] = 3;
	B[0][1] = 1;
	B[0][2] = 2;
	B[1][0] = 0;
	B[1][1] = -1;
	B[1][2] = 4;
	cout << '\n' << A << '\n' << B << '\n';
	cout << A*B;//-3 2 2
				// 6 2 4
				// 0 -3 12
	cout << a4*a3;
}
int main()
{
	testMatrix();
	Matrix A(2,2), f(2,1);
	double coef = 1.0;
	A[0][0] = 0.2;
	A[0][1] = 0.1;
	A[1][0] = 0.1;
	A[1][1] = 0.2;
	f[0][0] = 0.1;
	f[1][0] = -0.1;
	AltTriang sys(A*coef, f*coef, 13);
	cout<<sys.solve();
	return 0;
}