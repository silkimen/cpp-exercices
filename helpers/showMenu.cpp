#include <iostream>

using namespace std;

int showMenu() {
  const int min = 0;
  const int max = 4;

  int selection = -1;

  while (true) {
    cout << "Bitte wählen Sie eine der folgenden Optionen:" << endl;
    cout << "1. Zeichen einlesen" << endl;
    cout << "2. Caesar-Schlüssel einlesen" << endl;
    cout << "3. Zeichen verschlüsseln" << endl;
    cout << "4. Zeichen entschlüsseln" << endl;
    cout << endl;
    cout << "0. Programm beenden" << endl;
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