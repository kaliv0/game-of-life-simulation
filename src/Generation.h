#ifndef GENERATION_H
#define GENERATION_H

#include <cstdlib>
#include <string>
#include <vector>

#include "Cell.h"

class Generation {
  Cell cells[MAX_ROW + 1][MAX_COL + 1];

public:
  void create_cell(int row, int column);
  // Draw all the cells
  void display();

  void populate_randomly();
  // Will the Cell at (row, column) survive to the next generation?
  bool will_survive(int row, int column);
  // Will a Cell be born at (row, column) in the next generation?
  bool will_create(int row, int column);

  void update_to_next_generation(const Generation &next);
};

// Non-member function
// Calculate which cells survive to the next generation and which are born
void calculate_next_generation(Generation &current, Generation &next);

#endif // GENERATION_H
