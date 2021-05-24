#include "FinanceManager.h"

int FinanceManager:: getLoggedInUserId()
{
    return LOGGED_IN_USER_ID;
}
Finance FinanceManager:: addNewFinance(string financeType, int financeId)
{
    Finance finance;
//    DateManager dateManager;
//    char dateStr[11];
    string dateStr;
    vector <Finance> finances;
    int dateInt, amount, test=210514;
    string item;
    cout << "Is this " << financeType << " from today? y/n" << endl;
    cin.sync();
    char answear = AuxiliaryMethods::getChar();
    if (answear=='y')
    {
//        dateInt = 210524;
        dateStr = dateManager.getActualDateFromTheSystem();
        dateManager.setDate(dateStr);
    }
    else
    {
//        DateManager:: getDateFromTheUser
//        char dateStr[11] = DateManager::getDate();
        cout << "Please, type the date in the 'yyyy-mm-dd format'" << endl;
        cin.sync();
        cin >> dateStr;
        cout << "dateStr: " << dateStr << endl;
        dateManager.setDate(dateStr);
        dateInt = dateManager.convertStringDateToIntDate(dateStr);
        while (dateManager.isDateCorrect(dateInt)==false)
        {
            cin.sync();
            cin >> dateStr;
            cout << "dateStr: " << dateStr << endl;
            dateManager.setDate(dateStr);
            dateInt = dateManager.convertStringDateToIntDate(dateStr);
        }
//            dateManager.setDate(dateStr);
//        dateManager.setDate(dateInt);
    }
    finance.setDate(dateInt);
    finance.setDateStr(dateStr);
    cout << "What is the name for that " << financeType << "?" << endl;
    cin.sync();
    item = AuxiliaryMethods::getTheLine();

    finance.setItem(item);
    cout << "How much have it cost?" << endl;
    cin.sync();

    cin >> amount;
    finance.setAmount(amount);
    finance.setUserId(LOGGED_IN_USER_ID);
    finance.setFinanceId(financeId);
    finances.push_back(finance);

    return finance;
//    xmlIncomeFile.save
}
