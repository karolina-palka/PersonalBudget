#ifndef BALANCEMANAGER_H_INCLUDED
#define BALANCEMANAGER_H_INCLUDED
#include <iostream>
#include <string>
#include "IncomeManager.h"
#include "ExpenseManager.h"

class BalanceManager
{
    IncomeManager* incomeManager;
    ExpenseManager* expenseManager;
//    const string INCOMES_FILE_NAME;

    public:
    BalanceManager(string incomes_file_name)
    {
        incomeManager = NULL;
        expenseManager = NULL;
        incomeManager = new IncomeManager(incomes_file_name);
    }
    ~BalanceManager()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    }
};
#endif // BALANCEMANAGER_H_INCLUDED
