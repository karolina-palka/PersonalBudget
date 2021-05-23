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
};


#endif // EXPENSEMANAGER_H_INCLUDED
