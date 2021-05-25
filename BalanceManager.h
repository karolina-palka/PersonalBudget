#ifndef BALANCEMANAGER_H_INCLUDED
#define BALANCEMANAGER_H_INCLUDED
#include <iostream>
#include <string>
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "DateManager.h"

class BalanceManager
{
    IncomeManager* incomeManager;
    ExpenseManager* expenseManager;

    public:
    BalanceManager(string incomes_file_name, string expenses_file_name, int loggedInUserId)
    {
        incomeManager = NULL;
        expenseManager = NULL;
        incomeManager = new IncomeManager(incomes_file_name, loggedInUserId);
        expenseManager = new ExpenseManager(expenses_file_name, loggedInUserId);
    }
    ~BalanceManager()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    }
    void addNewIncome();
    void addNewExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showTheChosenPeriodBalance();
    char chooseOptionFromTheUserMenu();
};
#endif // BALANCEMANAGER_H_INCLUDED
