#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void bubbleSort(int numbers[], int length) {
  for (int i = 1; i < length; ++i) {
    for (int j = 0; j < length - 1; ++j) {
      // ascending
      // if (numbers[j] > numbers[j + 1]) {

      // descending
      // if (numbers[j] < numbers[j + 1]) {

      if (numbers[j] > numbers[j + 1]) {
        int tmp = numbers[j];

        numbers[j] = numbers[j + 1];
        numbers[j + 1] = tmp;
      }
    }
  }
}

#endif