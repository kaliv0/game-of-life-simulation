#include "Generation.h"

void Generation::create_cell(int row, int column) {
  cells[row][column].create();
}

// Draw all cells
void Generation::display() {
  std::cout << ERASE_SCREEN;
  for (int row = 0; row < MAX_ROW; ++row) {
    for (int column = 0; column < MAX_COL; ++column) {
      cells[row][column].draw(row, column);
    }
    std::cout << HIDE_CURSOR;
  }
}

// Populate Generation with cells, at random
void Generation::populate_randomly() {
  time_t now;
  time(&now);
  srand(now);

  for (int row = 0; row < MAX_ROW; ++row) {
    for (int column = 0; column < MAX_COL; ++column) {
      if (rand() / CUTOFF == 0) {
        create_cell(row, column);
      }
    }
  }
}

// Will the Cell at (row, column) survive to the next generation?
bool Generation::will_survive(int row, int column) {
  if (!cells[row][column].is_alive()) {
    // There is no Cell at this position!
    return false;
  }

  // Find the number of live neighbours for this Cell
  //
  //   x x x
  //   x o x
  //   x x x
  int neighbours =
      cells[row - 1][column - 1].is_alive() +
      cells[row - 1][column].is_alive() +
      cells[row - 1][column + 1].is_alive() +
      cells[row][column - 1].is_alive() + cells[row][column + 1].is_alive() +
      cells[row + 1][column - 1].is_alive() +
      cells[row + 1][column].is_alive() + cells[row + 1][column + 1].is_alive();

  if (neighbours < MIN_NEIGHBOURS || neighbours > MAX_NEIGHBOURS) {
    // Cell has died
    return false;
  }

  // If we get here, the Cell has survived
  return true;
}

// Will a Cell be born at (row, column) in the next generation?
bool Generation::will_create(int row, int column) {
  if (cells[row][column].is_alive()) {
    // There already is a Cell at this position!
    return false;
  }

  // Find the number of parents for this Cell
  //
  //   x x x
  //   x o x
  //   x x x
  int parents =
      cells[row - 1][column - 1].is_alive() +
      cells[row - 1][column].is_alive() +
      cells[row - 1][column + 1].is_alive() +
      cells[row][column - 1].is_alive() + cells[row][column + 1].is_alive() +
      cells[row + 1][column - 1].is_alive() +
      cells[row + 1][column].is_alive() + cells[row + 1][column + 1].is_alive();

  if (parents < MIN_PARENTS || parents > MAX_PARENTS) {
    // Cannot create_cell a Cell here
    return false;
  }
  // If we get here, a new Cell can be born
  return true;
}

void Generation::update_to_next_generation(const Generation &next) {
  for (int row = 0; row < MAX_ROW; ++row) {
    for (int column = 0; column < MAX_COL; ++column) {
      cells[row][column] = next.cells[row][column];
    }
  }
}

// By default, all cells in the next generation are initially unpopulated
// Calculate which live cells survive
// and unpopulated cells are populated in the next generation
void calculate_next_generation(Generation &current, Generation &next) {
  for (int row = 0; row < MAX_ROW; ++row) {
    for (int column = 0; column < MAX_COL; ++column) {
      if (current.will_survive(row, column) ||
          current.will_create(row, column)) {
        next.create_cell(row, column);
      }
    }
  }
}
