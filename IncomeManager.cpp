#include "IncomeManager.h"

void IncomeManager:: addNewIncome()
{
    Finance income;
    int loggedInUserId = getLoggedInUserId();
    cout << "loggedInUserId: " << loggedInUserId << endl;
    int financeId = xmlIncomeFile.getNewFinanceId("income", getLoggedInUserId());
//    int financeId = incomes.size() +1;

    income = addNewFinance("income", financeId);
    xmlIncomeFile.addFinancesToXmlFile(income, "income");
}
void IncomeManager:: sortOutIncomesByDate()
{
    sortOutFinancesByDate(incomes);
    for (int i=0; i< incomes.size(); i++)
    {
        cout << "User ID: " << incomes[i].getUserId() << endl;
        cout << "finance ID: " << incomes[i].getFinanceId() << endl;
        cout << "date: " << incomes[i].getDate() << endl;
        cout << "dateStr: " << incomes[i].getDateStr() << endl;
        cout << "Item: " << incomes[i].getItem() << endl;
        cout << "Amount: " << incomes[i].getAmount() << endl;
    }
}
double IncomeManager:: sumUpIncomesFromTheCurrentMonth()
{
    double allIncomes = sumUpFinancesFromTheCurrentMonth(incomes);
}
double IncomeManager:: sumUpIncomesFromThePreviousMonth()
{
    double allIncomes = sumUpFinancesFromThePreviousMonth(incomes);
}
