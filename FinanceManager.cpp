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

    char answear = AuxiliaryMethods::getChar();
    if (answear=='y')
    {
        dateStr = DateManager::getActualDateFromTheSystem();
        dateInt = DateManager::convertStringDateToIntDate(dateStr);
    }
    else
    {
        cout << "Please, type the date in the 'yyyy-mm-dd format'" << endl;
        dateStr = AuxiliaryMethods::getTheLine();

        while (DateManager::isDateCorrect(dateStr)==false)
        {
            dateStr = AuxiliaryMethods::getTheLine();
        }
    }
    dateInt = DateManager::convertStringDateToIntDate(dateStr);
    finance.setDate(dateInt);
    finance.setDateStr(dateStr);
    cout << "What is the name for that " << financeType << "?" << endl;

    item = AuxiliaryMethods::getTheLine();

    finance.setItem(item);
    cout << "How much have it cost?" << endl;

    amountStr = AuxiliaryMethods::getTheLine();
    amount = AuxiliaryMethods::convertStringToDouble(amountStr);
    finance.setAmount(amount);
    finance.setUserId(LOGGED_IN_USER_ID);
    finance.setFinanceId(financeId);

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
    double allFinances=0.0, amount = 0.0;
    int monthFromFinances=0, dateFromFinances=0, actualMonth=0;
    string actualDate = DateManager::getActualDateFromTheSystem();

    int actualDateInt = DateManager::convertStringDateToIntDate(actualDate) - previousMonth;

    actualMonth = (actualDateInt%10000 - actualDateInt%100)/100;

    for (int i=0; i<finances.size(); i++)
    {
        dateFromFinances = finances[i].getDate();
        monthFromFinances = (dateFromFinances%10000 - dateFromFinances%100)/100;

        if ( monthFromFinances == actualMonth)
        {
            displayFinanceData(finances[i]);
            amount = finances[i].getAmount();
            allFinances += amount;
        }
    }
    return allFinances;
}
double FinanceManager:: sumUpFinancesFromTheCurrentMonth(vector <Finance> &finances)
{
    return sumUpFinancesFromTheMonth(finances, 0);
}
double FinanceManager:: sumUpFinancesFromThePreviousMonth(vector <Finance> &finances)
{
    return sumUpFinancesFromTheMonth(finances, 100);
}

double FinanceManager:: sumUpFinancesFromTheChosenPeriod(vector <Finance> &finances, int dateFromInt, int dateUpToInt)
{
    double allFinances=0.0;
    int monthFromFinances=0, dateFromFinances=0, monthFrom=0, monthUpTo=0;

    for (int i=0; i<finances.size(); i++)
    {
        dateFromFinances = finances[i].getDate();

        if ( dateFromFinances >= dateFromInt && dateFromFinances <= dateUpToInt )
        {
            displayFinanceData(finances[i]);
            allFinances += finances[i].getAmount();
        }
    }
    return allFinances;
}
void FinanceManager:: displayFinanceData(Finance &finance)
{
    cout << "userId: " <<  finance.getUserId() << "| " << "financeId: " << finance.getFinanceId() << "| " ;
    cout << "date: " << finance.getDateStr() << "| "<< endl;
    cout << "item: " << finance.getItem() << "| " << endl;
    cout << "amount: " << finance.getAmount() << "| " << endl;
    cout << "---------------------------------------" << endl;
}
