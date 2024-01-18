#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
// Display symbols for type of cells
const char live_cell{'#'};
const char dead_cell{' '};

// Clear screen and move cursor back to "home" position
const std::string clear_screen{"\x1b[2J"};
// Clear screen and delete all lines saved in the scroll-back buffer
const std::string erase_screen{"\x1b[3J"};
// Hide cursor
const std::string hide_cursor{"\x1b[?25l"};
// Live cell color
const std::string green_color{"\x1b[32m"};

// Standard ANSI console
const int max_row = 24;
const int max_col = 80;

// Re-adjusted for bigger screen
//const int max_row = 54;
//const int max_col = 210;

// Populate at random
const int factor = 5;
const int cutoff = RAND_MAX / factor;

// Conway's parameters
const int min_neighbours = 2;
const int max_neighbours = 3;
const int min_parents = 3;
const int max_parents = 3;

// Generation age
const int generation_age = 500;
} // namespace constants

#endif // CONSTANTS_H
