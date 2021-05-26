#include "ExpenseManager.h"

void ExpenseManager:: addNewExpense()
{
    Finance expense;
//    int financeId = xmlExpensesFile.getNewFinanceId("expense", getLoggedInUserId());

    int financeId = xmlExpensesFile.getNewFinanceId("expense");
    expense = addNewFinance("expense", financeId);
    expenses.push_back(expense);
    xmlExpensesFile.addFinancesToXmlFile(expense, "expense");
}
void ExpenseManager:: sortOutExpensesByDate()
{
    sortOutFinancesByDate(expenses);
}

double ExpenseManager:: sumUpExpensesFromTheCurrentMonth()
{
    double allExpenses = sumUpFinancesFromTheCurrentMonth(expenses);
    return allExpenses;
}
double ExpenseManager:: sumUpExpensesFromThePreviousMonth()
{
    double allExpenses = sumUpFinancesFromThePreviousMonth(expenses);
    return allExpenses;
}
double ExpenseManager:: sumUpExpensesFromTheChosenPeriod(int dateFrom, int dateUpToInt)
{
    double allExpenses = sumUpFinancesFromTheChosenPeriod(expenses, dateFrom, dateUpToInt);
    return allExpenses;
}
