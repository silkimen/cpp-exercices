#include <iostream>

#include "../helpers/bubbleSort.cpp"
#include "../helpers/fillArray.cpp"
#include "../helpers/findInArray.cpp"
#include "../helpers/insertionSort.cpp"
#include "../helpers/mergeSort.cpp"
#include "../helpers/power.cpp"
#include "../helpers/selectionSort.cpp"

using namespace std;
const int MAXLENGTH = 100;

int arrayLength = 10;
int arrayUrsprung[MAXLENGTH];
int arrayBubbleSort[MAXLENGTH];
int arraySelectionSort[MAXLENGTH];

// *********************************************************************

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
      fillArray(arraySelectionSort, length, -1);

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
    arraySelectionSort[i] = arrayUrsprung[i];

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
    arraySelectionSort[i] = arrayUrsprung[i];
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

void doSelectionSort() {
  selectionSort(arraySelectionSort, arrayLength);
  cout << "Die Zahlen wurden mit Selection Sort sortiert: ";
  printArray(arraySelectionSort, arrayLength);
}

void findElementInUrsprungArray() {
  int value = 0;

  cout << "Bitte geben Sie den Wert ein nach dem gesucht werden soll: ";
  cin >> value;

  cout << "Ursprung Array: ";
  findElement(arrayUrsprung, arrayLength, value);
}

void findElementInSortedArrays() {
  int value = 0;

  cout << "Bitte geben Sie den Wert ein nach dem gesucht werden soll: ";
  cin >> value;

  cout << "Bubble Sort Array: ";
  findElement(arrayBubbleSort, arrayLength, value);

  cout << "Selection Sort Array: ";
  findElement(arraySelectionSort, arrayLength, value);
}

void printUrsprungArray() {
  cout << "Ursprung Array: ";
  printArray(arrayUrsprung, arrayLength);
}

void printSortedArrays() {
  cout << "Bubble Sort Array: ";
  printArray(arrayBubbleSort, arrayLength);

  cout << "Selection Sort Array: ";
  printArray(arraySelectionSort, arrayLength);
}

void printComparisonCount() {
  cout << "Es sind folgende Anzahl an logischen Vergleichen notwendig:" << endl;
  cout << "Bei Bubble Sort (n-1)^2: " << power(arrayLength - 1, 2) << endl;
  cout << "Bei Selection Sort (n^2-n)/2: " << (power(arrayLength, 2) - arrayLength) / 2 << endl;
}

int showMenu() {
  const int min = 0;
  const int max = 11;

  int selection = -1;

  while (true) {
    cout << "Bitte wählen Sie eine der folgenden Optionen:" << endl;
    cout << "1. Größe des Arrays festlegen und Zurücksetzen des Arrays (alle Einträge erhalten den Wert -1)" << endl;
    cout << "2. Zahlen in das Array über die Tastatur einlesen (alle Zahlen nacheinander)" << endl;
    cout << "3. Eine Zahl im Array an einer bestimmten Position speichern (Positionsangabe wird über die Tastatur eingelesen)" << endl;
    cout << "4. Zufallszahlen generieren und das gesamte Array automatisch befüllen" << endl;
    cout << "5. Sortierung des Arrays mit BubbleSort" << endl;
    cout << "6. Sortierung des Arrays mit SelectionSort" << endl;
    cout << "7. Suche nach einem Element im Ursprungsarray (Ausgabe: Element 3 steht an Pos. 7)" << endl;
    cout << "8. Suche nach einem Element in den sortierten Arrays (Ausgabe: Element 3 steht an Pos. 7)" << endl;
    cout << "9. Ausgabe des Ursprungsarrays" << endl;
    cout << "10. Ausgabe der sortierten Arrays (BubbleSort und SelectionSort)" << endl;
    cout << "11. Ausgabe der Anzahl der notwendigen logischen Vergleiche bis zur vollständigen Sortierung (BubbleSort und SelectionSort)" << endl;
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
  cout << "Aufgabe: Zahlen sortieren" << endl;
  cout << "=========================" << endl;
  cout << endl;

  while (true) {
    switch (showMenu()) {
      case 1:
        initArray();
        break;
      case 2:
        readNumbers();
        break;
      case 3:
        readNumber();
        break;
      case 4:
        doFillArrayWithRandom();
        break;
      case 5:
        doBubbleSort();
        break;
      case 6:
        doSelectionSort();
        break;
      case 7:
        findElementInUrsprungArray();
        break;
      case 8:
        findElementInSortedArrays();
        break;
      case 9:
        printUrsprungArray();
        break;
      case 10:
        printSortedArrays();
        break;
      case 11:
        printComparisonCount();
        break;
      case 0:
        return 0;
    }

    cout << endl;
  }
}