#include "Cell.h"

void Cell::draw(int row, int col) const {
  // Move the cursor to row n, column m
  // These are 1-based, i.e. row 1 is the first row
  std::cout << GREEN_COLOR << "\x1b[" << row + 1 << ";" << col + 1 << "H";
  std::cout << (alive ? LIVE_CELL : DEAD_CELL);
}

void Cell::create() { alive = true; }

bool Cell::is_alive() const { return alive; }
