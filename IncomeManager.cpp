#include "IncomeManager.h"

void IncomeManager:: addNewIncome()
{
    Finance income;
//    vector <Finance> incomes;
    int financeId = incomes.size() +1;

    income = addNewFinance("income", financeId);
    xmlIncomeFile.addFinancesToXmlFile(income, "income");
}
