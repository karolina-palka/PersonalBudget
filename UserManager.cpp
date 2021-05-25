#include <iostream>
#include "UserManager.h"

vector <User> UserManager:: registerNewUser()
{
    string username, password;

    User user = getNewUserData();
    users.push_back(user);
    xmlUsersFile.addUserToXmlFile(user);

    cout << "User account created:" << endl;
    return users;
}
User UserManager:: getNewUserData()
{
    User user;
    string password, login, name, surname;

    do
    {
        cout << "Enter the username: " << endl;
        cin >> login;
        user.setLogin(login);

    } while (isTheLoginInUse(user.getLogin()) == true);

//    user.setLogin(login);
    user.setId(users.size()+ 1);
    cout << "Enter password: " << endl;
    cin >> password;
    user.setPassword(password);
    cout << "Enter the name: " << endl;
    cin >> name;
    user.setName(name);
    cout << "Enter the surname: " << endl;
    cin >> surname;
    user.setSurname(surname);
    cout << user.getSurname() << endl;

    return user;
}

int UserManager:: getTheUserId()
{
    return loggedInUserId;
}
bool UserManager:: isTheLoginInUse(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (login == users[i].getLogin())
        {
            cout << endl << "There is already user with that login. Please try another username." << endl;
            return true;
        }
    }
    return false;
}
int UserManager::logInToUserAccount()
{
    int i =0;
    string username, password;
    cout << "Enter the username: " << endl;
    username = AuxiliaryMethods::getTheLine();

    while (i < users.size())
    {
        loggedInUserId = checkPasswordUpToThreeTimes(users[i], username);
        if (loggedInUserId>0)
        {
            cout << "id: " << loggedInUserId << endl;
            return loggedInUserId;
        }
        else if (loggedInUserId==-1)
            return loggedInUserId;
        i++;
    }
    cout << "There is no account with that username. Please try another one." << endl;
    return loggedInUserId;
}
int UserManager::checkPasswordUpToThreeTimes(User user, string username)
{
    int id = 0;
    string password="";
    string login = user.getLogin();

    if (user.getLogin() == username)
    {
        for (int j=0; j<3; j++)
        {
            cout << "Enter password. It's your " << j+1 << " trial." << endl;
            cin >> password;
            if (password == user.getPassword())
            {
                id = user.getId();
                cout << "You are logged in." << endl;
                return id;
            }
        }
        cout << "You entered an incorrect password 3 times. The program will stop for 3 seconds." <<endl;
        id = -1;
        Sleep(3000);
    }
    return id;
}
int UserManager:: logOutTheUser()
{
     loggedInUserId = 0;
     return loggedInUserId;
}
char UserManager:: chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}
bool UserManager:: isTheUserLoggedIn()
{
    if(loggedInUserId==0 || loggedInUserId==-1 )
        return false;
    else
        return true;
}
void UserManager:: changePassword()
{
    string newPassword="";
    cout << "Please, type in new password: " << endl;
    newPassword = AuxiliaryMethods::getTheLine();
    for (int i=0; i< users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            xmlUsersFile.saveNewPasswordToXmlFile(users[i]);
        }
    }
}
