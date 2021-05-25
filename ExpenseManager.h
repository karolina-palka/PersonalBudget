#ifndef EXPENSEMANAGER_H_INCLUDED
#define EXPENSEMANAGER_H_INCLUDED
#include <iostream>
#include <vector>
#include "Finance.h"
#include "XmlFinanceFile.h"
#include "FinanceManager.h"


using namespace std;

class ExpenseManager: public FinanceManager
{
    vector <Finance> expenses;
    XmlFinanceFile xmlExpensesFile;

public:
    ExpenseManager(string fileName, int loggedInUserId): FinanceManager(loggedInUserId), xmlExpensesFile(fileName)
    {
//        if(xmlExpensesFile.isAnyFinanceSaved("expense", loggedInUserId)==true)
//        {
             expenses = xmlExpensesFile.loadFinancesFromFile("expense", loggedInUserId);
//        }
//        else
//        {
//            cout << "You don't have any expenses saved yet." << endl;
//        }
//        cout << "LOGGED_IN_USER_ID: " << loggedInUserId << endl;
    }
    void addNewExpense();
    void sortOutExpensesByDate();
    double sumUpExpensesFromTheCurrentMonth();
    double sumUpExpensesFromThePreviousMonth();
};


#endif // EXPENSEMANAGER_H_INCLUDED
