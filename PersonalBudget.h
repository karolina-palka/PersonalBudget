#ifndef PERSONALBUDGET_H_INCLUDED
#define PERSONALBUDGET_H_INCLUDED
#include "UserManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget(string usersFileName): userManager(usersFileName){};
    void registerNewUser();
    void logInToUserAccount();
    void logOutTheUser();
};


#endif // PERSONALBUDGET_H_INCLUDED
