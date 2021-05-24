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
