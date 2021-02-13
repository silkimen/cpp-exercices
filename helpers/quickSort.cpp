#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int data[], int indexA, int indexB) {
  int tmp = data[indexA];

  data[indexA] = data[indexB];
  data[indexB] = tmp;
}

void recursiveQuicksort(int data[], int left, int right) {
  int ptr;
  int pivot;

  if (right - left < 1) {
    return;
  }

  ptr = left;
  pivot = left + 1;

  while (++ptr <= right) {
    if (data[ptr] < data[left]) {
      swap(data, ptr, pivot);
      ++pivot;
    }
  }

  swap(data, left, pivot - 1);
  recursiveQuicksort(data, left, pivot - 1);
  recursiveQuicksort(data, pivot, right);
}

void quickSort(int numbers[], int length) {
  recursiveQuicksort(numbers, 0, length - 1);
}

#endif