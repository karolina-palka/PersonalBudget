#ifndef FINANCEMANAGER_H_INCLUDED
#define FINANCEMANAGER_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <string>
#include "Finance.h"
#include <vector>
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class FinanceManager
{
    const int LOGGED_IN_USER_ID;

    double sumUpFinancesFromTheMonth(vector <Finance> &finances, int previousMonth);
    void displayFinanceData(Finance &finance);

public:
    FinanceManager(int loggedInUserId): LOGGED_IN_USER_ID(loggedInUserId){};
    Finance addNewFinance(string financeType, int financeId);
    int getLoggedInUserId();
    void sortOutFinancesByDate(vector <Finance> &finances);
    double sumUpFinancesFromTheCurrentMonth(vector <Finance> &finances);
    double sumUpFinancesFromThePreviousMonth(vector <Finance> &finances);
    double sumUpFinancesFromTheChosenPeriod(vector <Finance> &finances, int dateFrom, int dateUpToInt);

};


#endif // FINANCEMANAGER_H_INCLUDED
