#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

void mergeSort(int numbers[], int length) {
  if (length == 1) {
    return;
  }

  int left[length / 2];
  int right[(length + 1) / 2];

  for (int i = 0; i < length / 2; ++i) {
    left[i] = numbers[i];
  }

  for (int i = length / 2; i < length; ++i) {
    right[i - length / 2] = numbers[i];
  }

  mergeSort(left, length / 2);
  mergeSort(right, (length + 1) / 2);

  int *pos1 = &left[0];
  int *pos2 = &right[0];

  for (int i = 0; i < length; ++i) {
    if (*pos1 <= *pos2) {
      numbers[i] = *pos1;
      if (pos1 != &right[(length + 1) / 2 - 1]) {
        if (pos1 == &left[length / 2 - 1]) {
          pos1 = &right[(length + 1) / 2 - 1];
        } else {
          ++pos1;
        }
      }
    } else {
      numbers[i] = *pos2;
      if (pos2 == &right[(length + 1) / 2 - 1]) {
        pos2 = &left[length / 2 - 1];
      } else {
        ++pos2;
      }
    }
  }
}

#endif