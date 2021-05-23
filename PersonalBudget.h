#ifndef PERSONALBUDGET_H_INCLUDED
#define PERSONALBUDGET_H_INCLUDED
#include "UserManager.h"
#include "BalanceManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BalanceManager* balanceManager;

public:
    PersonalBudget(string usersFileName): userManager(usersFileName)
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
//    void loadUsersFromFile();
};


#endif // PERSONALBUDGET_H_INCLUDED
