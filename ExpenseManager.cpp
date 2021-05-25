#include "ExpenseManager.h"

void ExpenseManager:: addNewExpense()
{
    Finance expense;
//    int financeId = expenses.size() +1;
    int financeId = xmlExpensesFile.getNewFinanceId("expense", getLoggedInUserId());

    expense = addNewFinance("expense", financeId);
    xmlExpensesFile.addFinancesToXmlFile(expense, "expense");
}
void ExpenseManager:: sortOutExpensesByDate()
{
    sortOutFinancesByDate(expenses);
    for (int i=0; i< expenses.size(); i++)
    {
        cout << "userId: " <<  expenses[i].getUserId() << endl;
        cout << "financeId: " << expenses[i].getFinanceId() << endl;
        cout << "date: " << expenses[i].getDate() << endl;
        cout << "dateStr: " << expenses[i].getDateStr() << endl;
        cout << "item: " << expenses[i].getItem() << endl;
        cout << "amount: " << expenses[i].getAmount() << endl;
    }
}
double ExpenseManager:: sumUpExpensesFromTheCurrentMonth()
{
    double allExpenses = sumUpFinancesFromTheCurrentMonth(expenses);
}
double ExpenseManager:: sumUpExpensesFromThePreviousMonth()
{
    double allExpenses = sumUpFinancesFromThePreviousMonth(expenses);
}
