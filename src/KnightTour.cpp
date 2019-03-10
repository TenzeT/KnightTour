/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-09-2019
Description: File containing definitions for the functions of the KnightTour.h header file
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "KnightTour.h"


KnightTour::KnightTour() 
{}

KnightTour::KnightTour(int &startLocRow, int &startLocCol)
	: numMovesMade_(0)
{
	setStartLocation(startLocRow, startLocCol);
	initializeGrids();
}

void KnightTour::setStartLocation(int &startLocRow, int &startLocCol)
{
	using std::cout;
	using std::endl;
	
	if (existsOnBoard(startLocRow) && existsOnBoard(startLocCol)) {
		currentRow_ = startLocRow;
		currentColumn_ = startLocCol;
	}
	else {
		cout << "Invalid start location." << endl;
	}
}

bool KnightTour::runTour()
{
	while (numMovesMade_ < GRID_SIZE * GRID_SIZE) {
		makeMove();
	}
	
	printGrid();
	
	return true;
}

void KnightTour::printGrid() const
{

	using std::cout;
	using std::endl;

	for (size_t row = 0; row < GRID_SIZE; ++row) {
		for (size_t column = 0; column < GRID_SIZE; ++column) {
			cout << std::setw(3) << board_[row][column] << " ";
		}
		cout << endl;
	}
}

void KnightTour::makeMove() {
	int tempRow = 0;
	int tempColumn = 0;
	int oldMoveValue = 99;
	unsigned int bestMoveIndex = 0;

	// Find best of all possible moves
	for (unsigned int i = 0; i < GRID_SIZE; ++i) {
		tempRow = currentRow_ + vertical_[i];
		tempColumn = currentColumn_ + horizontal_[i];

		if (existsOnBoard(tempRow) && existsOnBoard(tempColumn)) {
			int tempMoveValue = accessibility_[tempRow][tempColumn];

			// If this move is more strategic and not visited
			if (tempMoveValue < oldMoveValue && board_[tempRow][tempColumn] == 99) {
				bestMoveIndex = i;
				oldMoveValue = tempMoveValue;
			}
		}
	}

	// Make the move
	currentRow_ += vertical_[bestMoveIndex];
	currentColumn_ += horizontal_[bestMoveIndex];
	
	// Update move-history board
	board_[currentRow_][currentColumn_] = ++numMovesMade_;
}

bool KnightTour::existsOnBoard(int testingVal) const 
{
	return (testingVal >= 0 && testingVal < GRID_SIZE);
}

void KnightTour::initializeGrids() {
	
	// Initialize base grid
	for (size_t row = 0; row < GRID_SIZE; ++row) {
		for (size_t column = 0; column < GRID_SIZE; ++column)
			board_[row][column] = 99;
	}

	// Initialize starting location
	board_[currentRow_][currentColumn_] = 0;

	// Initialize horizontal moves array
	horizontal_ = { 2, 1, -1, -2, -2, -1, 1, 2 };

	// Initialize vertical moves array
	vertical_ = { -1, -2, -2, -1, 1, 2, 2, 1 };

	// Initialize accessibility heuristic grid
	accessibility_ = { 2, 3, 4, 4, 4, 4, 3, 2,
					   3, 4, 6, 6, 6, 6, 4, 3,
					   4, 6, 8, 8, 8, 8, 6, 4,
					   4, 6, 8, 8, 8, 8, 6, 4,
				       4, 6, 8, 8, 8, 8, 6, 4,
					   4, 6, 8, 8, 8, 8, 6, 4,
					   3, 4, 6, 6, 6, 6, 4, 3,
					   2, 3, 4, 4, 4, 4, 3, 2
			         };
}