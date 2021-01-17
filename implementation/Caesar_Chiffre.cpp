#include <iostream>

using namespace std;

char showMenu() {
  char selection = 0;

  while (true) {
    cout << "Bitte waehlen Sie eine der folgenden Optionen:" << endl;
    cout << "1: Text verschluesseln" << endl;
    cout << "2: Text entschluesseln" << endl;
    cout << endl;
    cout << "q: Programm beenden" << endl;
    cout << endl;
    cout << "Ihre Auswahl: ";

    cin >> selection;

    if ((selection >= '1' && selection <= '2') || selection == 'q') {
      cout << endl;
      return selection;
    }

    cout << "Ungueltige Eingabe!"
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

void encode() {
  int key = readKey();

  cout << "Bitte geben Sie den Text ein, der verschluesselt werden soll (nur a - z): ";
  string text;
  cin >> text;

  for (int i = 0; i < text.length(); ++i) {
    if (text[i] < 97 || text[i] > 122) {
      cout << "Ungueltige Eingabe!" << endl;
      return;
    }

    text[i] = (text[i] - 97 + key) % 26 + 97;
  }

  cout << "Verschluesselt: " << text << endl;
}

void decode() {
  int key = readKey();

  cout << "Bitte geben Sie den Text ein, der entschluesselt werden soll (nur a - z): ";
  string text;
  cin >> text;

  for (int i = 0; i < text.length(); ++i) {
    if (text[i] < 97 || text[i] > 122) {
      cout << "Ungueltige Eingabe!" << endl;
      return;
    }

    text[i] = (text[i] - 71 - key) % 26 + 97;
  }

  cout << "Entschluesselt: " << text << endl;
}

int main() {
  cout << endl;
  cout << "Aufgabe: Caeser Verschluesselung" << endl;
  cout << "================================" << endl;
  cout << endl;

  while (true) {
    switch (showMenu()) {
      case '1':
        encode();
        break;
      case '2':
        decode();
        break;
      case 'q':
        return 0;
    }

    cout << endl;
  }
}