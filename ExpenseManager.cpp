#include "ExpenseManager.h"

void ExpenseManager:: addNewExpense()
{
    Finance expense;
//    int financeId = expenses.size() +1;
    int financeId = xmlExpensesFile.getNewFinanceId("expense", getLoggedInUserId());

    expense = addNewFinance("expense", financeId);
    xmlExpensesFile.addFinancesToXmlFile(expense, "expense");
}
