#include <iostream>

using namespace std;

int showMenu() {
  const int min = 1;
  const int max = 5;

  int selection = -1;

  while (true) {
    cout << "Bitte wählen Sie eine der folgenden Optionen:" << endl;
    cout << "1. Zeichen einlesen" << endl;
    cout << "2. Caesar-Schlüssel einlesen" << endl;
    cout << "3. Zeichen verschlüsseln" << endl;
    cout << "4. Zeichen entschlüsseln" << endl;
    cout << endl;
    cout << "5. Programm beenden" << endl;
    cout << endl;
    cout << "\tIhre Eingabe: ";

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

bool checkInput(char character, int key) {
  if (character == -1) {
    cout << "Sie haben noch kein Zeichen eingebeben." << endl;
    return false;
  }

  if (key == -1) {
    cout << "Sie haben noch keinen Schlüssel eingebeben." << endl;
    return false;
  }

  // Daten sind richtig eingegeben worden
  return true;
}

int main() {
  int key = -1;
  char character = -1;

  while (true) {
    switch (showMenu()) {
      case 1:
        character = readChar();
        break;
      case 2:
        key = readKey();
        break;
      case 3:
        if (checkInput(character, key)) {
          cout << "Verschlüsselter Wert: " << crypt(character, key) << endl;
        }
        break;
      case 4:
        if (checkInput(character, key)) {
          cout << "Entschlüsselter Wert: " << decrypt(character, key) << endl;
        }
        break;
      case 5:
        return 0;
    }

    cout << endl;
  }
}