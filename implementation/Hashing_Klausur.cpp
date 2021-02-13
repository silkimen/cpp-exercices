#include <iostream>

using namespace std;

int hashSize = 100;

char arrayElement[100];
int arrayHashwert[100];

char elementBuffer = '#';
int hashBuffer = -1;

int readHashSize() {
  int size;

  while (true) {
    cout << "Größe der Hash Tabelle bestimmen (5 - 100): ";
    cin >> size;

    if (size >= 5 && size <= 100) {
      return size;
    }

    cout << "Ungültige Eingabe!" << endl;
  }
}

void initArrays() {
  for (int i = 0; i < hashSize; ++i) {
    arrayHashwert[i] = -1;
    arrayElement[i] = '#';
  }
}

char readElement() {
  char element;

  while (true) {
    cout << "Bitte geben Sie einen Buchstaben ein [A - Z]: ";
    cin >> element;

    if (element >= 'A' && element <= 'Z') {
      return element;
    }

    cout << "Ungültige Eingabe!" << endl;
  }
}

int getElementCount() {
  int count = 0;

  for (int i = 0; i < hashSize; ++i) {
    if (arrayHashwert[i] > -1) {
      ++count;
    }
  }

  return count;
}

void showStats() {
  int filledCount = getElementCount();
  int fillGrade = 100 * filledCount / hashSize;

  cout << "\tEingelesener Buchstabe im Pufferspeicher: '" << elementBuffer << "', Hashwert: " << hashBuffer << endl;
  cout << "\tFüllgrad der Hashtabelle: " << filledCount << "/" << hashSize << " --> " << fillGrade << "%" << endl;
}

int getHashValue(char element) {
  int i = 0;
  int hashValue = -1;

  do {
    // h(z) = (h(z) + i) mod m
    hashValue = (element - ('A' - 1) + i++) % hashSize;
  } while (arrayHashwert[hashValue] != -1);

  return hashValue;
}

void readAndCalculate() {
  if (getElementCount() == hashSize) {
    cout << "Hash Tabelle ist voll, bitte löschen Sie Positionen!" << endl;
    return;
  }

  elementBuffer = readElement();
  hashBuffer = getHashValue(elementBuffer);
}

void saveValue() {
  if (hashBuffer == -1) {
    cout << "Bitte erst Buchstaben in Pufferspeicher einlesen." << endl;
    return;
  }

  arrayElement[hashBuffer] = elementBuffer;
  arrayHashwert[hashBuffer] = hashBuffer;

  elementBuffer = '#';
  hashBuffer = -1;

  cout << "Die Daten wurden gespeichert und der Buffer zurückgesetzt." << endl;
}

void deleteElement() {
  int min = 0;
  int max = hashSize - 1;
  int position;

  while (true) {
    cout << "Welche Position soll gelöscht werden [" << min << " - " << max << "]? ";
    cin >> position;

    if (position >= min && position <= max) {
      arrayElement[position] = '#';
      arrayHashwert[position] = -1;
      return;
    }

    cout << "Ungültige Eingabe!"
         << endl
         << endl;
  }
}

void showTable() {
  cout << "Inhalt der Hashtabelle: "
       << endl
       << endl;

  for (int i = 0; i < hashSize; ++i) {
    if (arrayHashwert[i] > -1) {
      cout << i << ": " << arrayElement[i] << "; Hashwert: " << arrayHashwert[i] << endl;
    } else {
      cout << i << ":" << endl;
    }
  }
}

int showMenu() {
  const int MIN = 0;
  const int MAX = 4;

  int selection = -1;

  while (true) {
    cout << endl;
    cout << "1. Buchstaben in den Pufferspeicher einlesen und Hashwert berechnen" << endl;
    cout << "2. Eintragung des Pufferspeichers in die Hash-Tabelle" << endl;
    cout << "3. Löschen einer bestimmten Position in der Hashtabelle" << endl;
    cout << "4. Ausgabe der Hashtabelle" << endl;
    cout << endl;
    cout << "0. Programm beenden" << endl;
    cout << endl;
    cout << "Ihre Eingabe: ";

    cin >> selection;

    if (selection >= MIN && selection <= MAX) {
      cout << endl;
      return selection;
    }

    cout << "Ungültige Eingabe!"
         << endl
         << endl;
  }
}

int main() {
  hashSize = readHashSize();
  initArrays();

  cout << "Hashing-Software"
       << endl
       << endl;

  while (true) {
    showStats();

    switch (showMenu()) {
      case 0:
        return 0;
      case 1:
        readAndCalculate();
        break;
      case 2:
        saveValue();
        break;
      case 3:
        deleteElement();
        break;
      case 4:
        showTable();
        break;
    }

    cout << endl
         << endl;
  }
}