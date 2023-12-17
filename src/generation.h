#ifndef GENERATION_H
#define GENERATION_H

#include <cstdlib>
#include <string>
#include <vector>

#include "cell.h"

class Generation {
  Cell _cells[constants::max_row + 1][constants::max_col + 1];

  int getSurroundingCells(int row, int column) const;

public:
  void display();

  void populateRandomly();

  void updateToNextGeneration(const Generation &next);

  bool willCellSurvive(int row, int column);

  bool willCreateCell(int row, int column);

  void createCell(int row, int column);
};

// Non-member function
void calculateNextGeneration(Generation &current, Generation &next);

#endif // GENERATION_H
