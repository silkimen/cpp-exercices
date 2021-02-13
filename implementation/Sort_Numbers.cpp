#include <iostream>

#include "../helpers/bubbleSort.cpp"
#include "../helpers/insertionSort.cpp"
#include "../helpers/mergeSort.cpp"
#include "../helpers/quickSort.cpp"

using namespace std;

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;
const int NUMBER_COUNT = 10;
const int DEMO_NUMBERS[NUMBER_COUNT] = {49, 26, 85, 17, 23, 68, 77, 11, 38, 42};

int numbers[NUMBER_COUNT];

void loadDemoNumbers() {
  for (int i = 0; i < NUMBER_COUNT; ++i) {
    numbers[i] = DEMO_NUMBERS[i];
  }

  cout << "Beispielzahlen wurden geladen." << endl;
}

void readNumbers() {
  int count = 0;

  cout << "Bitte geben Sie " << NUMBER_COUNT << " Zahlen zwischen " << MIN_NUMBER << " und " << MAX_NUMBER << " ein." << endl;

  while (count < NUMBER_COUNT) {
    cout << count + 1 << ". Zahl: ";
    cin >> numbers[count];

    if (numbers[count] < MIN_NUMBER || numbers[count] > MAX_NUMBER) {
      cout << "Ungueltige Eingabe!"
           << endl
           << endl;
    } else {
      ++count;
    }
  }

  cout << "Alle Zahlen wurden erfasst." << endl;
}

void printNumbers() {
  cout << "Folgende Zahlen sind im Array gespeichert: ";

  for (int i = 0; i < NUMBER_COUNT; ++i) {
    cout << numbers[i];

    if (i == NUMBER_COUNT - 1) {
      cout << endl;
    } else {
      cout << ", ";
    }
  }
}

void doBubbleSort() {
  bubbleSort(numbers, NUMBER_COUNT);
  cout << "Die Zahlen wurden mit Bubble Sort sortiert." << endl;
  printNumbers();
}

void doInsertionSort() {
  insertionSort(numbers, NUMBER_COUNT);
  cout << "Die Zahlen wurden mit Insertion Sort sortiert." << endl;
  printNumbers();
}

void doMergeSort() {
  mergeSort(numbers, NUMBER_COUNT);
  cout << "Die Zahlen wurden mit Merge Sort sortiert." << endl;
  printNumbers();
}

void doQuickSort() {
  quickSort(numbers, NUMBER_COUNT);
  cout << "Die Zahlen wurden mit Quick Sort sortiert." << endl;
  printNumbers();
}

char showMenu() {
  char selection = 0;

  while (true) {
    cout << "Bitte waehlen Sie eine der folgenden Optionen:" << endl;
    cout << "1: Zahlen einlesen" << endl;
    cout << "2: Beispielzahlen laden" << endl;
    cout << "3: Zahlen mit Bubble Sort sortieren" << endl;
    cout << "4: Zahlen mit Insertion Sort sortieren" << endl;
    cout << "5: Zahlen mit Merge Sort sortieren" << endl;
    cout << "6: Zahlen mit Quick Sort sortieren" << endl;
    cout << "7: Zahlen ausgeben" << endl;
    cout << endl;
    cout << "q: Programm beenden" << endl;
    cout << endl;
    cout << "Ihre Auswahl: ";

    cin >> selection;

    if ((selection >= '1' && selection <= '7') || selection == 'q') {
      cout << endl;
      return selection;
    }

    cout << "Ungueltige Eingabe!"
         << endl
         << endl;
  }
}

int main() {
  cout << endl;
  cout << "Aufgabe: Zahlen sortieren" << endl;
  cout << "=========================" << endl;
  cout << endl;

  loadDemoNumbers();
  cout << endl;

  while (true) {
    switch (showMenu()) {
      case '1':
        readNumbers();
        break;
      case '2':
        loadDemoNumbers();
        break;
      case '3':
        doBubbleSort();
        break;
      case '4':
        doInsertionSort();
        break;
      case '5':
        doMergeSort();
        break;
      case '6':
        doQuickSort();
        break;
      case '7':
        printNumbers();
        break;
      case 'q':
        return 0;
    }

    cout << endl;
  }
}