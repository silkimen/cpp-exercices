#ifndef FILLARRAY_H
#define FILLARRAY_H

void fillArray(int array[], int length, int value) {
  for (int i = 0; i < length; ++i) {
    array[i] = value;
  }
}

void fillArrayWithRandom(int array[], int length, int min, int max) {
  for (int i = 0; i < length; ++i) {
    array[i] = (rand() % (max - min + 1)) + min;
  }
}

#endif