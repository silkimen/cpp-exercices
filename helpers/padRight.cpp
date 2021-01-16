#ifndef PADRIGHT_H
#define PADRIGHT_H

#include <iostream>
using namespace std;

string padRight(string text, int count, char fillWith) {
  if (count > 0) {
    return padRight(text, --count, fillWith) + fillWith;
  }

  return text;
}

#endif