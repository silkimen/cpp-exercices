#include <iostream>

using namespace std;

int getLosNumber() {
  int max = 6;
  int min = 1;

  return (rand() % (max - min + 1)) + min;
}

int main() {
  int gezogeneNummer;
  int gewinnNummer;

  char weiterMachen = 'j';
  int anzahlGewonnen = 0;
  int anzahlVerloren = 0;

  while (weiterMachen == 'j') {
    cout << "Möchten Sie ein Los ziehen? (j = ja / n = nein): ";
    cin >> weiterMachen;

    if (weiterMachen == 'n') {
      return 0;
    }

    gezogeneNummer = getLosNumber();
    cout << "Sie haben folgende Losnummer gezogen: " << gezogeneNummer << endl;

    gewinnNummer = getLosNumber();
    cout << "Die Losnummer, die zum Gewinn führt lautet: " << gewinnNummer << endl;

    if (gezogeneNummer == gewinnNummer) {
      anzahlGewonnen++;
    } else {
      anzahlVerloren++;
    }

    cout << "Sie haben bisher " << anzahlGewonnen << " mal gewonnen." << endl;
    cout << "Sie haben bisher " << anzahlVerloren << " mal verloren." << endl;
  }
}