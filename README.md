# Game-of-Life
The “game of life” simulates the behaviour of a population of living cells that evolves from one generation to the next. 

A population is represented by a n x m two-dimensional array of cells, each cell being in one of two different states: alive or dead.

Each cell has 8 neighbouring cells surrounding it, and the next generation of cells is generated according to the following rules:

1.	Any live cell with fewer than 2 live neighbours dies, as if caused by under-population. (1 cell > die)
2.	Any live cell with more than 3 live neighbours dies, as if by overcrowding. (4 cell > die)
3.	Any live cell with 2 or 3 live neighbours lives on to the next generation. (2 or 3 cells > live)
4.	Any dead cell with exactly 3 live neighbours becomes a live cell, as if by reproduction.
