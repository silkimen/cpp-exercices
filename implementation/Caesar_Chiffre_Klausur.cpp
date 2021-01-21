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
    cout << "Bitte geben Sie einen Buchstaben ein (nur a - z): ";
    cin >> character;

    if (character >= 97 && character <= 122) {
      return character;
    }

    cout << "Ungueltige Eingabe!" << endl;
  }
}

char crypt(char input, int key) {
  return (input - 97 + key) % 26 + 97;
}

char decrypt(char input, int key) {
  return (input - 71 - key) % 26 + 97;
}

int main() {
  cout << endl;
  cout << "Aufgabe: Caeser Verschluesselung" << endl;
  cout << "================================" << endl;
  cout << endl;

  int key;
  char character;

  while (true) {
    switch (showMenu()) {
      case 1:
        key = readKey();
        character = readChar();
        cout << "Verschluesselter Wert: " << crypt(character, key) << endl;
        break;
      case 2:
        key = readKey();
        character = readChar();
        cout << "Entschluesselter Wert: " << decrypt(character, key) << endl;
        break;
      case 0:
        return 0;
    }

    cout << endl;
  }
}