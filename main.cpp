#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users-1.xml", "incomes-1.xml", "expenses.xml");

    char choice;
    while(true)
    {
        if (personalBudget.isTheUserLoggedIn())
        {
            choice = personalBudget.chooseOptionFromTheUserMenu();
            switch(choice)
            {
            case '1':
                {
                    personalBudget.addNewIncome();
                    break;
                }
            case '2':
                {
                    personalBudget.addNewExpense();
                    break;
                }
            case '3':
                {
                    personalBudget.showCurrentMonthBalance();
                    break;
                }
            case '4':
                {
                    personalBudget.showPreviousMonthBalance();
                    break;
                }
            case '5':
                {
                    personalBudget.showTheChosenPeriodBalance();
                    break;
                }
            case '6':
                {
                    personalBudget.changePassword();
                    break;
                }
            case '7':
                {
                    personalBudget.logOutTheUser();
                    break;
                }
            }
        }
        else
        {
            choice = personalBudget.chooseOptionFromMainMenu();
            switch(choice)
            {
            case '1':
                {
                    personalBudget.registerNewUser();
                    break;
                }
            case '2':
                {
                    personalBudget.logInToUserAccount();
                    break;
                }
            case '9':
                {
                    personalBudget.exitTheProgram();
                    break;
                }
            }
        }

    }


}
