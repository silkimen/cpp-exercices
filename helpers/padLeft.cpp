#ifndef PADLEFT_H
#define PADLEFT_H

#include <iostream>
using namespace std;

string padLeft(string text, int count, char fillWith) {
  if (count > 0) {
    return fillWith + padLeft(text, --count, fillWith);
  }

  return text;
}

#endif