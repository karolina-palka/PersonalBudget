#ifndef DATEMANAGER_H_INCLUDED
#define DATEMANAGER_H_INCLUDED
#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    char date[11];
//    int date;

public:
    void setDate(char newDate[11]);
    char getDate();
    int convertCharDateToIntDate(char dateToBeConverted[11]);
    bool isDateCorrect(int dateToBeChecked);
//    static void getDateFromTheUser();
};

#endif // DATEMANAGER_H_INCLUDED
