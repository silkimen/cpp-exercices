#ifndef GETDIGIT_H
#define GETDIGIT_H

#include "./power.cpp"

int getDigit(int number, int pos) {
  int divider = power(10, pos);
  int position = number / divider % 10;

  return position;
}

#endif