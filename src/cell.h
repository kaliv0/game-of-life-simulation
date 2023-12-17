#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "constants.h"

class Cell {
  bool _alive;

public:
  Cell() : _alive(false) {}

  void draw(int row, int col) const;

  void create() { _alive = true; }

  bool isAlive() const { return _alive; }
};

#endif // CELL_H
