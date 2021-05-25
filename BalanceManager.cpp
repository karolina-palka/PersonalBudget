#include "BalanceManager.h"

void BalanceManager:: addNewIncome()
{
    incomeManager->addNewIncome();
}
void BalanceManager:: addNewExpense()
{
    expenseManager->addNewExpense();
}
void BalanceManager:: showCurrentMonthBalance()
{
    ;
}
void BalanceManager:: sortOutExpensesByDate()
{
    expenseManager->sortOutExpensesByDate();
}
