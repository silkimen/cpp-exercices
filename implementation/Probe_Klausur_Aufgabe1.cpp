#include <iostream>

using namespace std;

const int arrayLength = 7;
const int numberArray[arrayLength] = {15, 7, 19, 3, 6, 2, 1};

int main() {
  int number;

  cout << "Bitte geben Sie die zu suchende Zahl ein: ";
  cin >> number;

  for (int i = 0; i < arrayLength; ++i) {
    if (numberArray[i] == number) {
      cout << "Die gesuchte Zahl " << number << " befindet sich an der " << i + 1 << ". Stelle (Array Position " << i << ")." << endl;
      return 0;
    }
  }

  cout << "Die gesuchte Zahl " << number << " befindet sich nicht im Array." << endl;
  return 1;
}