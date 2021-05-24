#include <iostream>
#include "PersonalBudget.h"

void PersonalBudget:: registerNewUser()
{
    userManager.registerNewUser();
}
void PersonalBudget:: logInToUserAccount()
{
    userManager.logInToUserAccount();
    balanceManager = new BalanceManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getTheUserId());
  //  cout << userManager.getTheUserId() << endl;
}
void PersonalBudget:: logOutTheUser()
{
    userManager.logOutTheUser();
}
void PersonalBudget:: addNewIncome()
{
    balanceManager->addNewIncome();
}
void PersonalBudget:: addNewExpense()
{
    balanceManager->addNewExpense();
}

//void PersonalBudget:: loadUsersFromFile()
//{
//    userManager.loadUsersFromFile();
//}
