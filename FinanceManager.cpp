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
    string dateStr, amountStr;
    vector <Finance> finances;
    int dateInt;
    double amount;
    string item;
    cout << "Is this " << financeType << " from today? y/n" << endl;
    cin.sync();
    char answear = AuxiliaryMethods::getChar();
    if (answear=='y')
    {
        dateStr = dateManager.getActualDateFromTheSystem();
        dateInt = dateManager.convertStringDateToIntDate(dateStr);
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

    cin >> amountStr;
    amount = AuxiliaryMethods::convertStringToDouble(amountStr);
    finance.setAmount(amount);
    finance.setUserId(LOGGED_IN_USER_ID);
    finance.setFinanceId(financeId);
    finances.push_back(finance);

    return finance;
//    xmlIncomeFile.save
}
void FinanceManager:: sortOutFinancesByDate(vector <Finance> &finances)
{
    struct dates_from_older
    {
        inline bool operator() (Finance& finance1,  Finance& finance2)
        {
            return (finance1.getDate() < finance2.getDate());
        }
    };
    sort(finances.begin(), finances.end(), dates_from_older());
}
double FinanceManager:: sumUpFinancesFromTheMonth(vector <Finance> &finances, int previousMonth)
{
    double allFinances=0;
    int monthFromFinances=0, dateFromFinances=0, actualMonth=0;
    string actualDate = dateManager.getActualDateFromTheSystem();
    cout << "actualDate: " << actualDate << endl;
    int actualDateInt = dateManager.convertStringDateToIntDate(actualDate) - previousMonth;
    cout << "actualDateInt: " << actualDateInt << endl;
    actualMonth = (actualDateInt%10000 - actualDateInt%100)/100;
    cout << "actualMonth: " << actualMonth << endl;
    for (int i=0; i<finances.size(); i++)
    {
        dateFromFinances = finances[i].getDate();
        monthFromFinances = (dateFromFinances%10000 - dateFromFinances%100)/100;
        cout << "monthFromFinances: " << monthFromFinances << endl;
        if ( monthFromFinances == actualMonth)
        {
            cout << "dateFromFinances: " << dateFromFinances << endl;
            cout << "monthFromFinances: " << monthFromFinances << endl;
            cout << "amount: " << finances[i].getAmount() << endl;
            allFinances += finances[i].getAmount();
        }
    }
    return allFinances;
}
double FinanceManager:: sumUpFinancesFromTheCurrentMonth(vector <Finance> &finances)
{
    int allFinances = sumUpFinancesFromTheMonth(finances, 0);
    return allFinances;
}
double FinanceManager:: sumUpFinancesFromThePreviousMonth(vector <Finance> &finances)
{
    int allFinances = sumUpFinancesFromTheMonth(finances, 100);
    return allFinances;
}
