#include <iostream>
//#include "UserManager.h"
#include "PersonalBudget.h"
//#include <cstdlib>
//#include <conio.h>
//#include "User.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users-1.xml", "incomes-1.xml", "expenses.xml");
//    personalBudget.registerNewUser();
//    personalBudget.loadUsersFromFile();

//    personalBudget.registerNewUser();
//    personalBudget.loadUsersFromFile();

//    personalBudget.registerNewUser();
    personalBudget.logInToUserAccount();
    personalBudget.showCurrentMonthBalance();
//    personalBudget.sortOutExpensesByDate();
//    personalBudget.addNewExpense();
//    personalBudget.logOutTheUser();


//    User user;o
//    string name = "Karolina";
//    user.setName(name);
//    cout << user.getName() << endl;
}
