#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    User getNewUserData();
    bool isLoginExisting(string login);

public:
    vector <User> registerNewUser();
};


#endif // USERMANAGER_H_INCLUDED
