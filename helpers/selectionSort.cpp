#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

void selectionSort(int numbers[], int length) {
  int left = 0;

  while (left < length) {
    int min = left;

    for (int i = left + 1; i < length; ++i) {
      // ascending
      // if (numbers[i] < numbers[min]) {

      // descending
      // if (numbers[i] > numbers[min]) {
      if (numbers[i] < numbers[min]) {
        min = i;
      }
    }

    int tmp = numbers[min];
    numbers[min] = numbers[left];
    numbers[left++] = tmp;
  }
}

#endif