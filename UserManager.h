#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <iostream>
#include "User.h"
#include "XmlUsersFile.h"
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    XmlUsersFile xmlUsersFile;

    User getNewUserData();
    bool isTheLoginInUse(string login);
    int checkPasswordUpToThreeTimes(User user, string username);

public:
    UserManager(string usersFileName): xmlUsersFile(usersFileName) {};
    vector <User> registerNewUser();
    void logInToUserAccount();
    void logOutTheUser();
};


#endif // USERMANAGER_H_INCLUDED
