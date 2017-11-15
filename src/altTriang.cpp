#include "altTriang.h"

/*bool AltTriang::isReady()
{
	return (A.gCol() != 0 && A.gRow() == f.gRow());
}*/

Matrix AltTriang::getR()
{
	Matrix m(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		for (int j = 0; j < A.gCol() - i; j++)
			if (i != j) m[i][j] = 0.5 * m[i][j];
			else m[i][j] = m[i][j];
	return m;
}

Matrix AltTriang::getRt()
{
	Matrix m(A.gRow(), A.gCol());
	for (int i = 0; i < A.gRow(); i++)
		for (int j = 0; j <= i; j++)
			if (i != j) m[i][j] = 0.5 * m[i][j];
			else m[i][j] = m[i][j];
	return m;
}
