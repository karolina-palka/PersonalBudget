#ifndef FINANCEMANAGER_H_INCLUDED
#define FINANCEMANAGER_H_INCLUDED
#include <iostream>

using namespace std;

class FinanceManager
{
    const int LOGGED_IN_USER_ID;
public:
    FinanceManager(int loggedInUserId): LOGGED_IN_USER_ID(loggedInUserId){};
    void addNewFinance();
};


#endif // FINANCEMANAGER_H_INCLUDED
