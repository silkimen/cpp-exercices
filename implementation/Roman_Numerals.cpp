#include <iostream>

#include "../helpers/getDigit.cpp"
#include "../helpers/padLeft.cpp"
#include "../helpers/padRight.cpp"
#include "../helpers/power.cpp"

using namespace std;

const char ONES[] = {'I', 'X', 'C', 'M'};
const char FIVES[] = {'V', 'L', 'D'};

string getRomanNumeral(string intermediateValue, int remainder, int decimalPower) {
  int decimalDigit = getDigit(remainder, decimalPower);
  int multiplier = power(10, decimalPower);

  if (remainder == 0) {
    return intermediateValue;
  }

  if (remainder < multiplier) {
    return getRomanNumeral(intermediateValue, remainder, --decimalPower);
  }

  switch (decimalDigit) {
    case 1:
    case 2:
    case 3:
      intermediateValue = padLeft(intermediateValue, decimalDigit, ONES[decimalPower]);
      break;
    case 4:
      intermediateValue = intermediateValue + ONES[decimalPower] + FIVES[decimalPower];
      break;
    case 5:
      intermediateValue = intermediateValue + FIVES[decimalPower];
      break;
    case 6:
    case 7:
    case 8:
      intermediateValue = padRight(intermediateValue + FIVES[decimalPower], decimalDigit - 5, ONES[decimalPower]);
      break;
    case 9:
      intermediateValue = intermediateValue + ONES[decimalPower] + ONES[decimalPower + 1];
      break;
    case 0:
      intermediateValue = intermediateValue + ONES[decimalPower + 1];
      break;
  }

  remainder -= decimalDigit * multiplier;

  return getRomanNumeral(intermediateValue, remainder, --decimalPower);
}

int listAllRomanNumerals() {
  for (int i = 1; i <= 3999; ++i) {
    cout << "Decimal: " << i << " --> Roman: " << getRomanNumeral("", i, 3) << endl;
  }

  return 0;
}

int inputAndConvertDecimal() {
  int decimal = 0;

  cout << "Geben Sie eine Dezimalzahl zwischen 1 und 3999 ein: ";
  cin >> decimal;

  if (decimal < 1 || decimal > 3999) {
    cout << "Die Zahl liegt nicht im gueltigen Wertebereich!" << endl;
    return 1;
  }

  cout << "Roemische Zahl: " << getRomanNumeral("", decimal, 3) << endl;
  return 0;
}

int main() {
  // return listAllRomanNumerals();
  return inputAndConvertDecimal();
}