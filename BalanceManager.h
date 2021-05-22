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

BalanceManager()
{
    incomeManager = NULL;
    expenseManager = NULL;
}
};
#endif // BALANCEMANAGER_H_INCLUDED
