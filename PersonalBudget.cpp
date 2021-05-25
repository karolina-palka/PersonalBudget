#include <iostream>
#include "PersonalBudget.h"

void PersonalBudget:: registerNewUser()
{
    userManager.registerNewUser();
    system("pause");
}
void PersonalBudget:: logInToUserAccount()
{
    userManager.logInToUserAccount();
    balanceManager = new BalanceManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getTheUserId());
    system("pause");
}
void PersonalBudget:: logOutTheUser()
{
    userManager.logOutTheUser();
    cout << "You are logged out." << endl;
    Sleep(1500);
}
void PersonalBudget:: addNewIncome()
{
    balanceManager->addNewIncome();
    system("pause");
}
void PersonalBudget:: addNewExpense()
{
    balanceManager->addNewExpense();
    system("pause");
}
void PersonalBudget:: showCurrentMonthBalance()
{
    balanceManager->showCurrentMonthBalance();
    system("pause");
}
void PersonalBudget:: showPreviousMonthBalance()
{
    balanceManager->showPreviousMonthBalance();
    system("pause");
}
void PersonalBudget:: showTheChosenPeriodBalance()
{
    balanceManager->showTheChosenPeriodBalance();
    system("pause");
}
char PersonalBudget:: chooseOptionFromMainMenu()
{
    userManager.chooseOptionFromMainMenu();
}
bool PersonalBudget:: isTheUserLoggedIn()
{
    userManager.isTheUserLoggedIn();
}
void PersonalBudget:: exitTheProgram()
{
    exit(0);
}
char PersonalBudget:: chooseOptionFromTheUserMenu()
{
    balanceManager->chooseOptionFromTheUserMenu();
}
