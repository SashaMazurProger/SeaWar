#include "AllowIndexes.h"

bool AllowIndexes(int vert, int horiz)
{
	if (vert >= 0 && vert <= 9 && horiz >= 0 && horiz <= 9)
		return true;
	else
		return false;
}