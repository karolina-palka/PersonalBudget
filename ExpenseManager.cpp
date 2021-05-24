#include "ExpenseManager.h"

void ExpenseManager:: addNewExpense()
{
    Finance expense;
    int financeId = expenses.size() +1;

    expense = addNewFinance("expense", financeId);
    xmlExpensesFile.addFinancesToXmlFile(expense, "expense");
}
