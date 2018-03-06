#include "Matrix.h"
#include "altTriang.h"
#include "GaussMethod.h"
#include "CramerMethod.h"
#include "SeidelMethod.h"
#include "../sln/calculatingModule/presentModule/print_read.h"

#include <algorithm>
using namespace std;
char *read = "../../../in.txt", *write = "out.txt";
void fff(Matrix &A, Matrix &f, ofstream &of, int canAltTriang)
{
	int size, min, max;
	cout << "print size, min and max\n";
	cin >> size >> min >> max;
	if (canAltTriang != 1)
		A = Matrix::createDiagDominMatrix(size, min, max);
	else
		A = Matrix::createSimmetricMatrix(size, min, max);
	f = Matrix::createVector(size, min, max);
	openWrite(getDate(), of);
	of << A << '\n' << f;
}
int main()
{
	ifstream is;
	ofstream of;
	Matrix A, f, x;
	int step, canAltTriang = 0;
	while (1)
	{
		string ans;
		cout << menu;
		cin >> ans;
		system("cls");
		if (ans == "0")
		{
			break;
		}
		else if (ans == "1")
		{
			canAltTriang = 0;
			fff(A, f, of, canAltTriang);
		}
		else if (ans == "2")
		{
			canAltTriang = 0;
			openRead(read, is);
			ReadSystem(is, A, f);
		}
		else if (ans == "3")
		{
			cout << "print number of iterations\n";
			cin >> step;
			
			openWrite(string(write), of);
			x = GaussMethod::getSolve(A, f);
			cout << "Gauss answer\n" << x;
			of << "Gauss answer\n" << x;
			
			x = CramerMethod::getSolve(A, f);
			cout << "Cramer answer\n" << x;
			of << "Cramer answer\n"<< x;
			
			x = SeidelMethod::getSolve(A, f, step + 2);
			cout << "Seidel answer, number of iterations = " << step << '\n' << x;
			of << "Seidel answer, number of iterations = "<<step << '\n' << x;

			x = SeidelMethod::getSolve(A, f, step);
			cout << "Jacob answer, number of iterations = " << step << '\n' << x;
			of << "Jacob answer, number of iterations = " << step << '\n' << x;
			
			if (canAltTriang)
			{
				x = AltTriang::getSolve(A, f, step);
				cout << "Alternately triangular answer, number of iterations = " << step << '\n' << x;
				of << "Alternately triangular answer, number of iterations = " << step << '\n' << x;
			}

			of.close();
			cout << "solve is completed\n";
		}
		else if (ans == "4")
		{
			canAltTriang = 1;
			fff(A, f, of, canAltTriang);
		}
	}
	return 0;
}