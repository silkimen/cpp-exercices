#include <iostream>

#include "../helpers/padLeft.cpp"
#include "../helpers/padRight.cpp"

using namespace std;

int MIN_ROW = 3;
int MAX_ROW = 20;

void printCharTriangle(int whitespaces, int rows, char character) {
  for (int i = 1; i <= rows; ++i) {
    cout << padLeft("", whitespaces - i, ' ');
    cout << padLeft("", i * 2 - 1, character) << endl;
  }
}

int readRowCount() {
  int count = 0;

  while (true) {
    cout << "Bitte geben die Anzahl der Zeilen (zwischen " << MIN_ROW << " und " << MAX_ROW << ") ein: ";
    cin >> count;

    if (count >= MIN_ROW && count <= MAX_ROW) {
      return count;
    }

    cout << "Ungueltige Eingabe!" << endl;
  }
}

char readSymbol() {
  char symbol;

  cout << "Bitte geben Sie das gewünschte Symbol ein: ";
  cin >> symbol;

  return symbol;
}

int main() {
  printCharTriangle(MAX_ROW, readRowCount(), readSymbol());

  return 0;
}