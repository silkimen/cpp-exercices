#ifndef PASCAL_H
#define PASCAL_H

using namespace std;

int getPascal(int row, int col) {
  if (col == 0 || col == row) {
    return 1;
  }

  if (col == 1 || (col + 1) == row) {
    return row;
  }

  return getPascal(row - 1, col - 1) + getPascal(row - 1, col);
}

#endif