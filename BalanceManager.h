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
//    const int LOGGED_IN_USER_ID;
//    const string INCOMES_FILE_NAME;

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
    void sortOutExpensesByDate();
};
#endif // BALANCEMANAGER_H_INCLUDED
