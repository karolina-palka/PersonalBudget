#include "IncomeManager.h"

void IncomeManager:: addNewIncome()
{
    Finance income;
    int loggedInUserId = getLoggedInUserId();
    cout << "loggedInUserId: " << loggedInUserId << endl;
    int financeId = xmlIncomeFile.getNewFinanceId("income", getLoggedInUserId());

    income = addNewFinance("income", financeId);
    incomes.push_back(income);
    xmlIncomeFile.addFinancesToXmlFile(income, "income");
}
void IncomeManager:: sortOutIncomesByDate()
{
    sortOutFinancesByDate(incomes);
}
double IncomeManager:: sumUpIncomesFromTheCurrentMonth()
{
    double allIncomes = sumUpFinancesFromTheCurrentMonth(incomes);
    return allIncomes;
}
double IncomeManager:: sumUpIncomesFromThePreviousMonth()
{
    double allIncomes = sumUpFinancesFromThePreviousMonth(incomes);
     return allIncomes;
}
double IncomeManager:: sumUpIncomesFromTheChosenPeriod(int dateFrom, int dateUpToInt)
{
    double allIncomes = sumUpFinancesFromTheChosenPeriod(incomes, dateFrom, dateUpToInt);
     return allIncomes;
}
