#include "FinanceManager.h"

int FinanceManager:: getLoggedInUserId()
{
    return LOGGED_IN_USER_ID;
}
Finance FinanceManager:: addNewFinance(string financeType, int financeId)
{
    Finance finance;

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
        dateStr = DateManager::getActualDateFromTheSystem();
        dateInt = DateManager::convertStringDateToIntDate(dateStr);
    }
    else
    {
        cout << "Please, type the date in the 'yyyy-mm-dd format'" << endl;
        cin.sync();
        cin >> dateStr;
//        cout << "dateStr: " << dateStr << endl;

        while (DateManager::isDateCorrect(dateStr)==false)
        {
            cin.sync();
            cin >> dateStr;
//            cout << "dateStr: " << dateStr << endl;
        }
    }
    dateInt = DateManager::convertStringDateToIntDate(dateStr);
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
    string actualDate = DateManager::getActualDateFromTheSystem();
//    cout << "actualDate: " << actualDate << endl;
    int actualDateInt = DateManager::convertStringDateToIntDate(actualDate) - previousMonth;
//    cout << "actualDateInt: " << actualDateInt << endl;
    actualMonth = (actualDateInt%10000 - actualDateInt%100)/100;
//    cout << "actualMonth: " << actualMonth << endl;
    for (int i=0; i<finances.size(); i++)
    {
        dateFromFinances = finances[i].getDate();
        monthFromFinances = (dateFromFinances%10000 - dateFromFinances%100)/100;
//        cout << "monthFromFinances: " << monthFromFinances << endl;
        if ( monthFromFinances == actualMonth)
        {
            displayFinanceData(finances[i]);
//            cout << "dateFromFinances: " << dateFromFinances << endl;
//            cout << "monthFromFinances: " << monthFromFinances << endl;
//            cout << "amount: " << finances[i].getAmount() << endl;
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

double FinanceManager:: sumUpFinancesFromTheChosenPeriod(vector <Finance> &finances, int dateFromInt, int dateUpToInt)
{
    double allFinances=0;
    int monthFromFinances=0, dateFromFinances=0, monthFrom=0, monthUpTo=0;

//    cout << "dateFromInt: " << dateFromInt << endl;
//    cout << "dateUpToInt: " << dateUpToInt << endl;
//    monthFrom = (dateFromInt%10000 - dateFromInt%100)/100;
//    monthUpTo = (dateUpToInt%10000 - dateUpToInt%100)/100;
//    cout << "monthFrom: " << monthFrom << endl;
    for (int i=0; i<finances.size(); i++)
    {
        dateFromFinances = finances[i].getDate();
//        monthFromFinances = (dateFromFinances%10000 - dateFromFinances%100)/100;
//        cout << "monthFromFinances: " << monthFromFinances << endl;
        if ( dateFromFinances >= dateFromInt && dateFromFinances <= dateUpToInt )
        {
            displayFinanceData(finances[i]);
//            cout << "dateFromFinances: " << dateFromFinances << endl;
//            cout << "monthFromFinances: " << monthFromFinances << endl;
//            cout << "amount: " << finances[i].getAmount() << endl;

            allFinances += finances[i].getAmount();
        }
    }
    return allFinances;
}
void FinanceManager:: displayFinanceData(Finance &finance)
{
    cout << "userId: " <<  finance.getUserId() << endl;
    cout << "financeId: " << finance.getFinanceId() << endl;
//    cout << "date: " << finance.getDate() << endl;
    cout << "date: " << finance.getDateStr() << endl;
    cout << "item: " << finance.getItem() << endl;
    cout << "amount: " << finance.getAmount() << endl;
}
