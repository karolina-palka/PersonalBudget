#ifndef PERSONALBUDGET_H_INCLUDED
#define PERSONALBUDGET_H_INCLUDED
#include <cstdlib>
#include "UserManager.h"
#include "BalanceManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BalanceManager* balanceManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    PersonalBudget(string usersFileName, string incomesFileName, string expense_file_name): userManager(usersFileName),
    INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expense_file_name)
    {
        balanceManager = NULL;
    };
    ~PersonalBudget()
    {
        delete balanceManager;
        balanceManager = NULL;
    }
    void registerNewUser();
    void logInToUserAccount();
    void logOutTheUser();
    void addNewIncome();
    void addNewExpense();
//    void sortOutExpensesByDate();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showTheChosenPeriodBalance();
    char chooseOptionFromMainMenu();
    bool isTheUserLoggedIn();
    void exitTheProgram();
    char chooseOptionFromTheUserMenu();
    void changePassword();

};


#endif // PERSONALBUDGET_H_INCLUDED
