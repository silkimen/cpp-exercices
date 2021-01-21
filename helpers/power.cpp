#ifndef POWER_H
#define POWER_H

/**
 *  Sinnvoller wäre es die cmath Funktion "pow()" zu verwenden,
 *  da wir diese aber in der Vorlesung nicht gelernt haben,
 *  hier meine eigene Implementierung
 **/
int power(int base, int exponent) {
  int result = 1;

  for (int i = 0; i < exponent; ++i) {
    result = result * base;
  }

  return result;
}

#endif