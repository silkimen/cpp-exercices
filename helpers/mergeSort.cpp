#ifndef MERGESORT_H
#define MERGESORT_H

void recursiveMergeSort(int arr[], int temp[], int left, int right) {
  if (left >= right) return;

  int mid = (right + left) / 2;
  recursiveMergeSort(arr, temp, left, mid);
  recursiveMergeSort(arr, temp, mid + 1, right);

  int i = left;
  int j = mid + 1;
  int tempi = left;

  for (; i <= mid && j <= right; ++tempi) {
    if (arr[i] < arr[j]) {
      temp[tempi] = arr[i++];
    } else {
      temp[tempi] = arr[j++];
    }
  }

  if (i > mid) {
    right = tempi - 1;
  }

  for (; tempi <= right; ++tempi, ++i) {
    temp[tempi] = arr[i];
  }

  for (int k = left; k <= right; ++k) {
    arr[k] = temp[k];
  }
}

void mergeSort(int numbers[], int length) {
  int temp[length];

  recursiveMergeSort(numbers, temp, 0, length - 1);
}

#endif