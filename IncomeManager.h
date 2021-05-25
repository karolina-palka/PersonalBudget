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
//    const string INCOMES_FILE_NAME;
//    const int LOGGED_IN_USER_ID;

public:
    IncomeManager(string fileName, int loggedInUserId): FinanceManager(loggedInUserId), xmlIncomeFile(fileName)
    {
//        if(xmlIncomeFile.isAnyFinanceSaved("income", loggedInUserId)==true)
//        {
            incomes = xmlIncomeFile.loadFinancesFromFile("income", loggedInUserId);
//        }
//        cout << "LOGGED_IN_USER_ID: " << loggedInUserId << endl;
    };
    void addNewIncome();
    void sortOutIncomesByDate();
    double sumUpIncomesFromTheCurrentMonth();
};

#endif // INCOMEMANAGER_H_INCLUDED
