#include <iostream>
#include "UserManager.h"

vector <User> UserManager:: registerNewUser()
{
    string username, password;

    User user = getNewUserData();
    users.push_back(user);

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
//int UserManager:: getNewUserId()
//{
//    if (uzytkownicy.empty() == true)
//        return 1;
//    else
//        return users.back().getId() + 1;
//}
bool UserManager:: isTheLoginInUse(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (login == users[i].getLogin())
        {
            cout << endl << "There is no user with that login." << endl;
            return true;
        }
    }
    return false;
}
void UserManager::logInToUserAccount()
{
    int i =0, loggedInUserId=0;
//    User user;
    string username, password;
    cout << "Enter the username: " << endl;
    cin >> username;
    int usersNumber = users.size();
//    cout << "usersNumber: " << usersNumber << endl;
    while (i < usersNumber)
    {
        loggedInUserId = checkPasswordUpToThreeTimes(users[i], username);
        if (loggedInUserId ==-1)
        {
            break;
//            return id;
        }
        else if (loggedInUserId> 0)
        {
            break;
        }
        i++;
    }
    Sleep(1500);
    cout << "id: " << loggedInUserId << endl;
//    cout << "You are logged in." << endl;
//    return id;
}
int UserManager::checkPasswordUpToThreeTimes(User user, string username)
{
    int id = 0;
    string password="";
    cout << "username: " << username << endl;
    string login = user.getLogin();
    cout << "user get login:" << login << endl;
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
