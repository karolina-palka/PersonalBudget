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
    double allIncomes = incomeManager->sumUpIncomesFromTheCurrentMonth();

    cout << "Total incomes: " <<allIncomes<< endl;
    double allExpenses = expenseManager->sumUpExpensesFromTheCurrentMonth();
    cout << "Total expenses: " << allExpenses << endl;
    cout << "Total balance: " << allIncomes - allExpenses << endl;

}
void BalanceManager:: showPreviousMonthBalance()
{
    cout << "Incomes from the previous month: " << endl;
    incomeManager->sortOutIncomesByDate();
    cout << "Expenses from the previous month: " << endl;
    expenseManager->sortOutExpensesByDate();
    double allIncomes = incomeManager->sumUpIncomesFromThePreviousMonth();

    cout << "Total incomes: " <<allIncomes<< endl;
    double allExpenses = expenseManager->sumUpExpensesFromThePreviousMonth();
    cout << "Total expenses: " << allExpenses << endl;
    cout << "Total balance: " << allIncomes - allExpenses << endl;
}
void BalanceManager:: showTheChosenPeriodBalance()
{
    cout << "Incomes from the chosen period: " << endl;
    incomeManager->sortOutIncomesByDate();
    cout << "Expenses from the chosen period: " << endl;
    expenseManager->sortOutExpensesByDate();
    cout << "Please, type in the date from which the period starts: " << endl;
    int dateFromInt = DateManager::getDateFromTheUser();
    cout << "Please, type in the date to which the period ends: " << endl;
    int dateUpToInt = DateManager::getDateFromTheUser();
    double allIncomes = incomeManager->sumUpIncomesFromTheChosenPeriod(dateFromInt, dateUpToInt);

    cout << "Total incomes: " <<allIncomes<< endl;
    double allExpenses = expenseManager->sumUpExpensesFromTheChosenPeriod(dateFromInt,dateUpToInt);
    cout << "Total expenses: " << allExpenses << endl;
    cout << "Total balance: " << allIncomes - allExpenses << endl;
}
/*void BalanceManager:: sortOutExpensesByDate()
{
    expenseManager->sortOutExpensesByDate();

}
void BalanceManager:: sortOutIncomesByDate()
{
    incomeManager->sortOutIncomesByDate();
}*/
