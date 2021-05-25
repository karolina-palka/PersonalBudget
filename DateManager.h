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
//    string date;

public:
//    static void setDate(string newDate);
//    static string getDate();
    static int convertStringDateToIntDate(string dateToBeConverted);
    static bool isDateCorrect(string dateToBeChecked);
    static string getActualDateFromTheSystem();
    static int getDateFromTheUser();
    static int getNumberOfDaysInActualMonth(string date);
//    static void getDateFromTheUser();
};

#endif // DATEMANAGER_H_INCLUDED
