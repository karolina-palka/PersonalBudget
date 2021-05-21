#include <iostream>
#include "UserManager.h"

vector <User> UserManager:: registerNewUser()
{
    string username, password;
//    vector <User> users;
//    users.push_back(User());
    User user = getNewUserData();
    users.push_back(User());

    cout << "User account created:" << endl;
    return users;
}
User UserManager:: getNewUserData()
{
    User user;
    string password, login, name, surname;

    do
    {
        cout << "Enter the username: ";
        cin >> login;

    } while (isLoginExisting( user.getLogin()) == true);

    user.setLogin(login);
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
bool UserManager:: isLoginExisting(string login)
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
