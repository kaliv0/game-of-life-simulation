# Conway's Game of Life

The universe of the <i>Game of Life</i> is an infinite, two-dimensional orthogonal grid of square cells,<br>
each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively).<br>
Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent.<br>
At each step in time, the following transitions occur:

- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

The initial pattern constitutes the seed of the system.<br>
The first generation is created by applying the above rules simultaneously to every cell in the seed, live or dead;<br>
births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick.<br>
Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.