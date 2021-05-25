#ifndef DATEMANAGER_H_INCLUDED
#define DATEMANAGER_H_INCLUDED
#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
public:

    static int convertStringDateToIntDate(string dateToBeConverted);
    static bool isDateCorrect(string dateToBeChecked);
    static string getActualDateFromTheSystem();
    static int getDateFromTheUser();
    static int getNumberOfDaysInActualMonth(string date);

};

#endif // DATEMANAGER_H_INCLUDED
