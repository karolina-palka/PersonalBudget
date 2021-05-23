#ifndef INCOMEMANAGER_H_INCLUDED
#define INCOMEMANAGER_H_INCLUDED
#include <iostream>
#include <vector>
#include "Finance.h"
#include "XmlFinanceFile.h"
#include "FinanceManager.h"

using namespace std;

class IncomeManager: public FinanceManager
{
    vector <Finance> incomes;
    XmlFinanceFile xmlIncomeFile;
    const string INCOMES_FILE_NAME;
public:
    IncomeManager(string fileName): INCOMES_FILE_NAME(fileName), xmlIncomeFile(fileName)
    {
        incomes = xmlIncomeFile.loadFinancesFromFile("income");
    };
};

#endif // INCOMEMANAGER_H_INCLUDED
