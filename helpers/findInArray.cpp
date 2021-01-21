#ifndef FINDINARRAY_H
#define FINDINARRAY_H

int findInArray(int array[], int length, int value) {
  for (int i = 0; i < length; ++i) {
    if (array[i] == value) {
      return i;
    }
  }

  return -1;
}

#endif