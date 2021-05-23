#ifndef EXPENSEMANAGER_H_INCLUDED
#define EXPENSEMANAGER_H_INCLUDED
#include <iostream>
#include <vector>
#include "Finance.h"
#include "XmlFinanceFile.h"
#include "FinanceManager.h"

using namespace std;

class ExpenseManager: public FinanceManager
{
    vector <Finance> expenses;
    XmlFinanceFile xmlExpensesFile;

public:
    ExpenseManager(string fileName, int loggedInUserId): FinanceManager(loggedInUserId), xmlExpensesFile(fileName)
    {
        expenses = xmlExpensesFile.loadFinancesFromFile("expense", loggedInUserId);
        cout << "LOGGED_IN_USER_ID: " << loggedInUserId << endl;
    }
};


#endif // EXPENSEMANAGER_H_INCLUDED
