/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-09-2019
Description: The header file for the KnightTour class includes function declarations
*/

#pragma once
#include <array>

class KnightTour {

public:
	KnightTour();
	explicit KnightTour(int &startLocRow, int &startLocCol);
	bool runTour();

private:
	static const size_t GRID_SIZE = 8;
	std::array< std::array < int, GRID_SIZE >, GRID_SIZE> board_;
	std::array< std::array< int, GRID_SIZE >, GRID_SIZE > accessibility_;
	unsigned int numMovesMade_;
	std::array< int, GRID_SIZE > horizontal_;
	std::array< int, GRID_SIZE > vertical_;
	unsigned int currentRow_;
	unsigned int currentColumn_;

	void initializeGrids();
	void setStartLocation(int &startLocRow, int &startLocCol);
	void printGrid() const;
	void makeMove();
	bool existsOnBoard(int testingVal) const;
};