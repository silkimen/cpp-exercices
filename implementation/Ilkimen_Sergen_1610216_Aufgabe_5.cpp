// Name: Ilkimen, Sergen
// Matr.Nr: 1610216
// Aufgabe: 5

#include <iostream>
using namespace std;

const int ARRAY_LENGTH = 1000;
char characters[ARRAY_LENGTH];

void fillArrayWithRandom(char array[], int length, char min, char max) {
  for (int i = 0; i < length; ++i) {
    array[i] = (rand() % (max - min + 1)) + min;
  }
}

void fillRandomChars() {
  cout << "Generiere zufällige Zeichen" << endl;
  fillArrayWithRandom(characters, ARRAY_LENGTH, 'A', 'Z');
}

void countOccurence(char character, char array[], int length) {
  int count = 0;

  for (int i = 0; i < length; ++i) {
    if (character == array[i]) {
      ++count;
    }
  }

  double percent = 100.0 * count / length;

  cout << "Das Zeichen '" << character << "' kommt " << count << " mal in der Liste vor." << endl;
  cout << "Das entspricht " << percent << "% der Einträge." << endl
       << endl;
}

char readCharacter() {
  char element;

  while (true) {
    cout << "Bitte geben Sie einen Buchstaben ein [A - Z]: ";
    cin >> element;

    if (element >= 'A' && element <= 'Z') {
      return element;
    }

    if (element >= 'a' && element <= 'z') {
      return element - ('a' - 'A');
    }

    cout << "Ungültige Eingabe!" << endl;
  }
}

int main() {
  cout << "Aufgabe 5: Zeichenzähler" << endl;
  cout << "========================" << endl
       << endl;

  fillRandomChars();
  countOccurence(readCharacter(), characters, ARRAY_LENGTH);
}
