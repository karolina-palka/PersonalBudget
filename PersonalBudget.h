#ifndef PERSONALBUDGET_H_INCLUDED
#define PERSONALBUDGET_H_INCLUDED
#include "UserManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
    void registerNewUser();
    void logInToUserAccount();
};


#endif // PERSONALBUDGET_H_INCLUDED
