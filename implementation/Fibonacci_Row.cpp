#include <iostream>

using namespace std;

void printFibonacciRow(int a, int b, string separator, int n) {
  cout << a;

  if (n > 0) {
    cout << separator;
    printFibonacciRow(b, a + b, separator, --n);
  } else {
    cout << endl;
  }
}

int main() {
  printFibonacciRow(0, 1, ", ", 30);

  return 0;
}