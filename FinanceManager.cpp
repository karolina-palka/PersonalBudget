#include "FinanceManager.h"

Finance FinanceManager:: addNewFinance(string financeType, int financeId)
{
//    string answear;
    Finance finance;
    vector <Finance> finances;
    int date, amount;
    string item;
    cout << "Is this " << financeType << " from today? y/n" << endl;
    cin.sync();
    char answear = AuxiliaryMethods::getChar();
    if (answear=='y')
    {
        date = 210524;
    }
    else
    {
        cout << "Please, type the date in the 'yyyy-mm-dd format" << endl;
        cin.sync();
        cin >> date;
    }
    finance.setDate(date);
    cout << "What is the name for that " << financeType << "?" << endl;
    cin.sync();
    item = AuxiliaryMethods::getTheLine();
//    getline(cin, item);
    finance.setItem(item);
    cout << "How much have it cost?" << endl;
    cin.sync();
//    amount = AuxiliaryMethods::getTheNumber();
    cin >> amount;
    finance.setAmount(amount);
    finance.setUserId(LOGGED_IN_USER_ID);
    finance.setFinanceId(financeId);
    finances.push_back(finance);

    return finance;
//    xmlIncomeFile.save
}
