#ifndef DATEMANAGER_H_INCLUDED
#define DATEMANAGER_H_INCLUDED
#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
//    char date[11];
//    int date;
    string date;

public:
    void setDate(string newDate);
    string getDate();
    int convertStringDateToIntDate(string dateToBeConverted);
    bool isDateCorrect(int dateToBeChecked);
    string getActualDateFromTheSystem();
    int getNumberOfDaysInActualMonth();
//    static void getDateFromTheUser();
};

#endif // DATEMANAGER_H_INCLUDED