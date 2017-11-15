#include "altTriang.h"

bool AltTriang::isReady()
{
	return (A.gCol() != 0 && A.gRow() == f.gRow());
}
