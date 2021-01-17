#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

void insertionSort(int data[], int length) {
  for (int i = 1; i < length; ++i) {
    int tmp = data[i];

    int j = i;

    while (j > 0 && tmp < data[j - 1]) {
      data[j] = data[j - 1];
      --j;
    }

    data[j] = tmp;
  }
}

#endif