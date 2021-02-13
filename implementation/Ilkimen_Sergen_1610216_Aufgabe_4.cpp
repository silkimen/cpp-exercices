// Name: Ilkimen, Sergen
// Matr.Nr: 1610216
// Aufgabe: 4

#include <iostream>
using namespace std;

const int MAX_SUM = 4500;
const int TRESHOLD = 20;
const double LOWER = 0.3;
const double UPPER = 0.35;

double getSum(int km, int workingDays) {
  double sum = 0;

  if (km <= TRESHOLD) {
    sum = LOWER * km * workingDays;
  } else {
    sum = (LOWER * TRESHOLD + UPPER * (km - TRESHOLD)) * workingDays;
  }

  if (sum < MAX_SUM) {
    return sum;
  }

  return MAX_SUM;
}

int main() {
  char quit = 'n';
  int km = 0;
  int workingDays = 0;

  cout << "Aufgabe 4: Fahrtkostenrechner" << endl;
  cout << "=============================" << endl
       << endl;

  while (quit != 'j') {
    cout << "Bitte geben Sie den einfachen Fahrtweg (in ganzen km) pro Tag ein: ";
    cin >> km;

    cout << "Bitte geben Sie die Anzahl der Arbeitstage ein: ";
    cin >> workingDays;

    cout << "Der absetzbare Betrag beträgt " << getSum(km, workingDays) << "€." << endl
         << endl;

    cout << "Möchten Sie das Programm beenden? [j/n]: ";
    cin >> quit;

    cout << endl;
  }
}
