#include "Matrix.h"
#include "altTriang.h"
#include "GaussMethod.h"
#include "../sln/calculatingModule/presentModule/print_read.h"
using namespace std;
char *read = "../../../in.txt", *write = "out.txt";

int main()
{
	ifstream is;
	openRead(read, is);
	Matrix A, f;

	ReadSystem(is, A, f);
	AltTriang sys(A, f, 25);
//	std::cout<<sys.solve();
	GaussMethod::setTriangle(A, f);
	cout << A;
//	cout << GaussMethod::getSolve(A, f);
	return 0;
}