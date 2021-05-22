#include <iostream>
//#include "UserManager.h"
#include "PersonalBudget.h"
//#include <cstdlib>
//#include <conio.h>
//#include "User.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    personalBudget.registerNewUser();
//    personalBudget.registerNewUser();
    personalBudget.logInToUserAccount();
    personalBudget.logOutTheUser();


//    User user;
//    string name = "Karolina";
//    user.setName(name);
//    cout << user.getName() << endl;
}
