#include <iostream>

#include "../helpers/getPascal.cpp"
#include "../helpers/padLeft.cpp"

using namespace std;

int main() {
  int rows = 5;

  for (int i = 0; i < rows; ++i) {
    cout << padLeft("", rows - i, ' ');

    for (int j = 0; j <= i; ++j) {
      cout << getPascal(i, j) << " ";
    }

    cout << endl;
  }

  return 0;
}