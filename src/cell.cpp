#include "cell.h"

void Cell::draw(int row, int col) const {
  // Move the cursor to row n, column m
  // These are 1-based, i.e. row 1 is the first row
  std::cout << constants::green_color << "\x1b[" << row + 1 << ";" << col + 1 << "H";
  std::cout << (_alive ? constants::live_cell : constants::dead_cell);
}