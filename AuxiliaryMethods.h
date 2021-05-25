#ifndef AUXILIARYMETHODS_H_INCLUDED
#define AUXILIARYMETHODS_H_INCLUDED

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string getTheLine();
    static string convertIntToString(int number);
    static string getTheNumber(string text, int charPosition);
    static int convertStringToInteger(string number);
    static char getChar();
    static double convertStringToDouble(string stringToBeConverted);
    static string convertDoubleToString(double numberToBeConverted);
//    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
//    static int wczytajLiczbeCalkowita();
};

#endif // AUXILIARYMETHODS_H_INCLUDED
