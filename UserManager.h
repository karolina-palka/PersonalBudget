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
    UserManager(string usersFileName): xmlUsersFile(usersFileName)
    {
        loggedInUserId = 0;
        users = xmlUsersFile.loadUsersFromFile();
        cout << "usersSize: " << users.size() << endl;
    };
    vector <User> registerNewUser();
    void logInToUserAccount();
    int logOutTheUser();
    int getTheUserId();
    char chooseOptionFromMainMenu();
    bool isTheUserLoggedIn();

};


#endif // USERMANAGER_H_INCLUDED
