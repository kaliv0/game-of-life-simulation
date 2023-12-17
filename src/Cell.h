#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "constants.h"

class Cell {
  bool alive;

public:
  Cell() : alive(false) {}
  // Draw Cell on Generation
  void draw(int row, int col) const;
  // Bring Cell to life
  void create();

  bool is_alive() const;
};

#endif // CELL_H
