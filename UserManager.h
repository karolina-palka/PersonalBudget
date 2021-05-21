#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <iostream>
#include "User.h"
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    User getNewUserData();
    bool isTheLoginInUse(string login);
    int checkPasswordUpToThreeTimes(User user, string username);

public:
    vector <User> registerNewUser();
    void logInToUserAccount();
};


#endif // USERMANAGER_H_INCLUDED
