/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-09-2019
Description: The driver class for KnightTour problem
*/

#include "stdafx.h"
#include "KnightTour.h"


int main()
{
	int startRow = 2, startColumn = 1;

	KnightTour knightTour(startRow, startColumn);
	knightTour.runTour();

    return 0;
}

