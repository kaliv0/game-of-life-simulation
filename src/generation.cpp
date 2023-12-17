#include "generation.h"

void Generation::createCell(int row, int column) {
  _cells[row][column].create();
}

void Generation::display() {
  std::cout << constants::erase_screen;
  for (int row = 0; row < constants::max_row; ++row) {
    for (int column = 0; column < constants::max_col; ++column) {
      _cells[row][column].draw(row, column);
    }
    std::cout << constants::hide_cursor;
  }
}

void Generation::populateRandomly() {
  time_t now;
  time(&now);
  // Comment out to reproduce same result everytime
  srand(now);

  for (int row = 0; row < constants::max_row; ++row) {
    for (int column = 0; column < constants::max_col; ++column) {
      if (rand() / constants::cutoff == 0) {
        createCell(row, column);
      }
    }
  }
}

bool Generation::willCellSurvive(int row, int column) {
  if (!_cells[row][column].isAlive()) {
    return false;
  }

  int neighbours = getSurroundingCells(row, column);
  if (neighbours < constants::min_neighbours ||
      neighbours > constants::max_neighbours) {
    return false;
  }
  return true;
}

bool Generation::willCreateCell(int row, int column) {
  if (_cells[row][column].isAlive()) {
    return false;
  }

  int parents = getSurroundingCells(row, column);
  if (parents < constants::min_parents || parents > constants::max_parents) {
    return false;
  }
  return true;
}

// Find the number of neighbours/parents for given Cell
int Generation::getSurroundingCells(int row, int column) const {
  return _cells[row - 1][column - 1].isAlive() +
         _cells[row - 1][column].isAlive() +
         _cells[row - 1][column + 1].isAlive() +
         _cells[row][column - 1].isAlive() + _cells[row][column + 1].isAlive() +
         _cells[row + 1][column - 1].isAlive() +
         _cells[row + 1][column].isAlive() +
         _cells[row + 1][column + 1].isAlive();
}

void Generation::updateToNextGeneration(const Generation &next) {
  for (int row = 0; row < constants::max_row; ++row) {
    for (int column = 0; column < constants::max_col; ++column) {
      _cells[row][column] = next._cells[row][column];
    }
  }
}

// By default, all cells in the next generation are initially unpopulated
// Calculate which live cells survive
// and unpopulated cells are populated in the next generation
void calculateNextGeneration(Generation &current, Generation &next) {
  for (int row = 0; row < constants::max_row; ++row) {
    for (int column = 0; column < constants::max_col; ++column) {
      if (current.willCellSurvive(row, column) ||
          current.willCreateCell(row, column)) {
        next.createCell(row, column);
      }
    }
  }
}
