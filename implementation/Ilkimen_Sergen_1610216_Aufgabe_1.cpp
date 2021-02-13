// Name: Ilkimen, Sergen
// Matr.Nr: 1610216
// Aufgabe: 1

#include <iostream>

using namespace std;
const int MAXLENGTH = 100;

int arrayLength = 2;
int arrayUrsprung[MAXLENGTH];
int arrayBubbleSort[MAXLENGTH];

// *********************************************************************

void fillArray(int array[], int length, int value) {
  for (int i = 0; i < length; ++i) {
    array[i] = value;
  }
}

void fillArrayWithRandom(int array[], int length, int min, int max) {
  for (int i = 0; i < length; ++i) {
    array[i] = (rand() % (max - min + 1)) + min;
  }
}

void printArray(int array[], int length) {
  for (int i = 0; i < length; ++i) {
    cout << array[i];

    if (i == length - 1) {
      cout << endl;
    } else {
      cout << ", ";
    }
  }
}

void bubbleSort(int numbers[], int length) {
  for (int i = 1; i < length; ++i) {
    for (int j = 0; j < length - 1; ++j) {
      // aufsteigend
      // if (numbers[j] > numbers[j + 1]) {

      // absteigend
      // if (numbers[j] < numbers[j + 1]) {

      if (numbers[j] > numbers[j + 1]) {
        int tmp = numbers[j];

        numbers[j] = numbers[j + 1];
        numbers[j + 1] = tmp;
      }
    }
  }
}

int findInArray(int array[], int length, int value) {
  for (int i = 0; i < length; ++i) {
    if (array[i] == value) {
      return i;
    }
  }

  return -1;
}

void findElement(int array[], int length, int value) {
  int result = findInArray(array, length, value);

  if (result == -1) {
    cout << "Der gesuchte Wert wurde nicht gefunden." << endl;
  } else {
    cout << "Element " << value << " steht an Pos. " << result << endl;
  }
}

// *********************************************************************

void initArray() {
  const int min = 2;
  const int max = 100;

  int length = 0;

  while (true) {
    cout << "Bitte geben Sie die gewünschte Array Größe (2 - 100) ein: ";
    cin >> length;

    if (length >= min && length <= max) {
      arrayLength = length;
      fillArray(arrayUrsprung, length, -1);
      fillArray(arrayBubbleSort, length, -1);
      cout << endl;

      return;
    }

    cout << "Ungültige Eingabe!"
         << endl
         << endl;
  }
}

void readNumbers() {
  const int min = 1;
  const int max = 199;
  const int length = arrayLength;

  int i = 0;

  cout << "Bitte geben Sie " << length << " Zahlen zwischen " << min << " und " << max << " ein." << endl;

  while (i < length) {
    cout << i + 1 << ". Zahl: ";
    cin >> arrayUrsprung[i];
    arrayBubbleSort[i] = arrayUrsprung[i];

    if (arrayUrsprung[i] < min || arrayUrsprung[i] > max) {
      cout << "Ungueltige Eingabe!"
           << endl
           << endl;
    } else {
      ++i;
    }
  }

  cout << "Alle Zahlen wurden erfasst." << endl;
}

void readNumber() {
  const int min = 0;
  const int max = 0;
  const int length = arrayLength;

  int position = -1;
  int value = -1;

  while (true) {
    cout << "An welcher Position soll die Zahl gespeichert werden? Position (0 - " << arrayLength - 1 << "): ";
    cin >> position;

    cout << "Welcher Wert soll gespeichert werden? Wert (" << min << " - " << max << "): ";
    cin >> value;

    if (position >= 0 && position < arrayLength && value >= min && value <= max) {
      cout << endl;
      return;
    }

    cout << "Ungültige Eingabe!"
         << endl
         << endl;
  }
}

void doFillArrayWithRandom() {
  fillArrayWithRandom(arrayUrsprung, arrayLength, 1, 199);

  for (int i = 0; i < arrayLength; ++i) {
    arrayBubbleSort[i] = arrayUrsprung[i];
  }

  cout << "Folgende Zahlen wurden zufällig generiert: ";
  printArray(arrayUrsprung, arrayLength);
}

void fillRandomNumbers(int array[], int length) {
}

void doBubbleSort() {
  bubbleSort(arrayBubbleSort, arrayLength);
  cout << "Die Zahlen wurden mit Bubble Sort sortiert: ";
  printArray(arrayBubbleSort, arrayLength);
}

void findElementInArrays() {
  int value = 0;

  cout << "Bitte geben Sie den Wert ein nach dem gesucht werden soll: ";
  cin >> value;

  cout << "Ursprung Array: ";
  findElement(arrayUrsprung, arrayLength, value);

  cout << "Bubble Sort Array: ";
  findElement(arrayBubbleSort, arrayLength, value);
}

void printArrays() {
  cout << "Ursprung Array: ";
  printArray(arrayUrsprung, arrayLength);

  cout << "Bubble Sort Array: ";
  printArray(arrayBubbleSort, arrayLength);
}

int showMenu() {
  const int min = 0;
  const int max = 6;

  int selection = -1;

  while (true) {
    cout << "Bitte wählen Sie eine der folgenden Optionen:" << endl;
    cout << "1. Zurücksetzen des Arrays (alle Einträge erhalten den Wert -1)" << endl;
    cout << "2. Zahlen in das Array über die Tastatur einlesen (alle Zahlen nacheinander)" << endl;
    cout << "3. Zufallszahlen generieren und das gesamte Array automatisch befüllen" << endl;
    cout << "4. Sortierung des Arrays mit BubbleSort" << endl;
    cout << "5. Suche nach einem Element in allen Arrays mit Positionsangabe" << endl;
    cout << "6. Ausgabe aller Arrays" << endl;
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

// *********************************************************************

int main() {
  cout << endl;
  cout << "Aufgabe 1: Zahlen sortieren" << endl;
  cout << "===========================" << endl;
  cout << endl;

  initArray();

  while (true) {
    switch (showMenu()) {
      case 1:
        initArray();
        break;
      case 2:
        readNumbers();
        break;
      case 3:
        doFillArrayWithRandom();
        break;
      case 4:
        doBubbleSort();
        break;
      case 5:
        findElementInArrays();
        break;
      case 6:
        printArrays();
        break;
      case 0:
        return 0;
    }

    cout << endl;
  }
}