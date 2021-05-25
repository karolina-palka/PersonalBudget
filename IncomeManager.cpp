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
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getFinanceId() << endl;
        cout << incomes[i].getDate() << endl;
    }
}
