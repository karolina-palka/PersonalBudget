#ifndef FINANCEMANAGER_H_INCLUDED
#define FINANCEMANAGER_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <string>
#include "Finance.h"
#include <vector>
#include "AuxiliaryMethods.h"

using namespace std;

class FinanceManager
{
    const int LOGGED_IN_USER_ID;
public:
    FinanceManager(int loggedInUserId): LOGGED_IN_USER_ID(loggedInUserId){};
    Finance addNewFinance(string financeType, int financeId);
};


#endif // FINANCEMANAGER_H_INCLUDED
