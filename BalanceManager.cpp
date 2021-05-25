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
    cout << "Incomes from the current month: " << endl;
    incomeManager->sortOutIncomesByDate();
    cout << "Expenses from the current month: " << endl;
    expenseManager->sortOutExpensesByDate();
}
void BalanceManager:: sortOutExpensesByDate()
{
    expenseManager->sortOutExpensesByDate();
}
void BalanceManager:: sortOutIncomesByDate()
{
    incomeManager->sortOutIncomesByDate();
}
