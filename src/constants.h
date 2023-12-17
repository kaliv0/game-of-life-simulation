#ifndef CONSTANTS_H
#define CONSTANTS_H

// Display symbols for type of cells
const char LIVE_CELL{'#'};
const char DEAD_CELL{' '};

// Clear screen and move cursor back to "home" position
const std::string CLEAR_SCREEN{"\x1b[2J"};
// Clear screen and delete all lines saved in the scroll-back buffer
const std::string ERASE_SCREEN{"\x1b[3J"};
// Hide cursor
const std::string HIDE_CURSOR{"\x1b[?25l"};
// Live cell color
const std::string GREEN_COLOR{"\x1b[32m"};

// Standard ANSI console
// const int MAX_ROW{24};
// const int MAX_COL{80};

// Re-adjusted for bigger screen
const int MAX_ROW = 54;
const int MAX_COL = 210;

// Populate at random
const int FACTOR = 5;
const int CUTOFF = RAND_MAX / FACTOR;

// Conway's parameters
const int MIN_NEIGHBOURS = 2;
const int MAX_NEIGHBOURS = 3;
const int MIN_PARENTS = 3;
const int MAX_PARENTS = 3;

// Generation age
const int GENERATION_AGE = 500;

#endif // CONSTANTS_H