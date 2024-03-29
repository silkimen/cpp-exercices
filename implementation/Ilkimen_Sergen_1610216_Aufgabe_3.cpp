// Name: Ilkimen, Sergen
// Matr.Nr: 1610216
// Aufgabe: 3

#include <iostream>

using namespace std;

int showMenu() {
  const int min = 0;
  const int max = 2;

  int selection = -1;

  while (true) {
    cout << "Bitte wählen Sie eine der folgenden Optionen:" << endl;
    cout << "1. Text verschluesseln" << endl;
    cout << "2. Text entschluesseln" << endl;
    cout << endl;
    cout << "0. Programm beenden" << endl;
    cout << endl;
    cout << "Ihre Eingabe: ";

    cin >> selection;

    if (selection >= min && selection <= max) {
      cout << endl;
      return selection;
    }

    cout << "Ungültige Eingabe!"
         << endl
         << endl;
  }
}

int readKey() {
  int key;

  while (true) {
    cout << "Bitte geben Sie den zu verwendenden Caesar Schluessel (1 - 25) ein: ";
    cin >> key;

    if (key > 0 && key < 26) {
      return key;
    }

    cout << "Ungueltige Eingabe!" << endl;
  }
}

char readChar() {
  char character;

  while (true) {
    cout << "Bitte geben Sie einen Buchstaben ein (nur a - z bzw. A - Z): ";
    cin >> character;

    if (character >= 'a' && character <= 'z' || character >= 'A' && character <= 'Z') {
      return character;
    }

    cout << "Ungueltige Eingabe!" << endl;
  }
}

char crypt(char input, int key, char offset) {
  return (input - offset + key) % 26 + offset;
}

char decrypt(char input, int key, char offset) {
  return (input - offset - key + 26) % 26 + offset;
}

int main() {
  cout << endl;
  cout << "Aufgabe 3: Caeser Verschluesselung" << endl;
  cout << "==================================" << endl;
  cout << endl;

  int key;
  char character;
  char result;

  while (true) {
    switch (showMenu()) {
      case 1:
        key = readKey();
        character = readChar();

        if (character >= 'a') {
          result = crypt(character, key, 'a');
        } else {
          result = crypt(character, key, 'A');
        }

        cout << "Verschluesselter Wert: " << result << endl;

        break;
      case 2:
        key = readKey();
        character = readChar();

        if (character >= 'a') {
          result = decrypt(character, key, 'a');
        } else {
          result = decrypt(character, key, 'A');
        }

        cout << "Entschluesselter Wert: " << result << endl;
        break;
      case 0:
        return 0;
    }

    cout << endl;
  }
}