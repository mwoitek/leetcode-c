#include <stdio.h>

#define GRID_SIZE 3

#define movesSize1 5
#define movesSize2 6
#define movesSize3 9

// Look for 3 occurrences of X or O in the i-th row.
// If there's a match, return the symbol. Otherwise, return whitespace.
char checkRow(char grid[][GRID_SIZE], int i)
{
  char symbol = grid[i][0];
  if (symbol == ' ') return symbol;
  for (int j = 1; j < GRID_SIZE; j++) {
    if (grid[i][j] != symbol) return ' ';
  }
  return symbol;
}

// Look for 3 occurrences of X or O in the j-th column.
// If there's a match, return the symbol. Otherwise, return whitespace.
char checkCol(char grid[][GRID_SIZE], int j)
{
  char symbol = grid[0][j];
  if (symbol == ' ') return symbol;
  for (int i = 1; i < GRID_SIZE; i++) {
    if (grid[i][j] != symbol) return ' ';
  }
  return symbol;
}

char checkMainDiagonal(char grid[][GRID_SIZE])
{
  char symbol = grid[0][0];
  if (symbol == ' ') return symbol;
  for (int i = 1; i < GRID_SIZE; i++) {
    if (grid[i][i] != symbol) return ' ';
  }
  return symbol;
}

char checkSecondaryDiagonal(char grid[][GRID_SIZE])
{
  int i = 0;
  int j = GRID_SIZE - 1;
  char symbol = grid[i++][j--];
  while (i < GRID_SIZE) {
    if (grid[i++][j--] != symbol) return ' ';
  }
  return symbol;
}

char* tictactoe(int** moves, int movesSize, int* movesColSize)
{
  char grid[GRID_SIZE][GRID_SIZE] = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}
  };
  char symbol = 'X';

  // Use moves to fill grid
  for (int i = 0; i < movesSize; i++) {
    int row = moves[i][0];
    int col = moves[i][1];
    grid[row][col] = symbol;
    symbol = symbol == 'X' ? 'O' : 'X';
  }

  // Check rows for a winner
  for (int i = 0; i < GRID_SIZE; i++) {
    char res = checkRow(grid, i);
    if (res == 'X')
      return "A";
    else if (res == 'O')
      return "B";
  }

  // Check columns for a winner
  for (int j = 0; j < GRID_SIZE; j++) {
    char res = checkCol(grid, j);
    if (res == 'X')
      return "A";
    else if (res == 'O')
      return "B";
  }

  // Check diagonals for a winner
  char res = checkMainDiagonal(grid);
  if (res == ' ') res = checkSecondaryDiagonal(grid);
  if (res == 'X')
    return "A";
  else if (res == 'O')
    return "B";

  return movesSize == GRID_SIZE * GRID_SIZE ? "Draw" : "Pending";
}

int main(void)
{
  int movesArr1[movesSize1][2] = {
      {0, 0},
      {2, 0},
      {1, 1},
      {2, 1},
      {2, 2}
  };
  int* moves1[movesSize1];
  for (int i = 0; i < movesSize1; i++) moves1[i] = movesArr1[i];
  printf("Case 1 - Output: %s\n", tictactoe(moves1, movesSize1, NULL));

  int movesArr2[movesSize2][2] = {
      {0, 0},
      {1, 1},
      {0, 1},
      {0, 2},
      {1, 0},
      {2, 0}
  };
  int* moves2[movesSize2];
  for (int i = 0; i < movesSize2; i++) moves2[i] = movesArr2[i];
  printf("Case 2 - Output: %s\n", tictactoe(moves2, movesSize2, NULL));

  int movesArr3[movesSize3][2] = {
      {0, 0},
      {1, 1},
      {2, 0},
      {1, 0},
      {1, 2},
      {2, 1},
      {0, 1},
      {0, 2},
      {2, 2}
  };
  int* moves3[movesSize3];
  for (int i = 0; i < movesSize3; i++) moves3[i] = movesArr3[i];
  printf("Case 3 - Output: %s\n", tictactoe(moves3, movesSize3, NULL));

  return 0;
}
