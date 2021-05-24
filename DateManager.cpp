#include "DateManager.h"

void DateManager:: setDate(string newDate)
{
//    for (int i=0; i<11; i++)
//    {
//        date[i] = newDate[i];
//    }
    date = newDate;
    cout << "date: " << date << endl;
}
string DateManager:: getDate()
{
    return date;
}
int DateManager:: convertStringDateToIntDate(string dateToBeConverted)
{
    string dateToConvert="";
    int dateInt=0;
//    cout << "date: " << date << endl;
    for (int i=2; i<11; i++)
    {
        if(dateToBeConverted[i]!='-')
        {
            dateToConvert += dateToBeConverted[i];
        }
    }
    dateInt = AuxiliaryMethods::convertStringToInteger(dateToConvert);
    cout << "dateInt: " << dateInt << endl;
    return dateInt;
}
bool DateManager:: isDateCorrect(int dateToBeChecked)
{
    string daysFromDate = "", actualDate="";
    int actualDateInt;
//    char sign;
//    cout << "date: " << date << endl;
    for (int j=4; j<8; j+=3)
    {
        if(date[j]!= '-')
        {
            cout << "Incorrect format. Please type in again." << endl;
            return false;
        }
    }
    actualDate=getActualDateFromTheSystem();
    actualDateInt = convertStringDateToIntDate(actualDate);
    cout << "actualDateInt: " << actualDateInt << endl;
    if (dateToBeChecked >= 101 && dateToBeChecked <= actualDateInt)
    {
        int daysOfActualMonth = getNumberOfDaysInActualMonth();
        cout << "daysOfActualMonth: " << daysOfActualMonth << endl;
        for (int i=8; i<10; i++)
        {
            daysFromDate += date[i];
        }
        int daysFromDateInt = AuxiliaryMethods::convertStringToInteger(daysFromDate);
        cout << "daysFromDateInt: " << daysFromDateInt << endl;
        if (daysFromDateInt>0 && daysFromDateInt <= daysOfActualMonth)

            return true;
        else
        {
            cout << "The date you typed in is incorrect. Please type again." << endl;
             return false;
        }
    }

    else
    {
        cout << "The date you typed in is incorrect. Please type again." << endl;
    }
        return false;
}
string DateManager:: getActualDateFromTheSystem()
{
    time_t now = time(0);
    const int MAXLEN = 11;
    char actualDate[MAXLEN];
    tm* local_time = localtime(&now);
    strftime(actualDate, MAXLEN, "%Y-%m-%d", local_time);
    cout << "actualDate: " << actualDate << endl;
    return actualDate;
}
int DateManager:: getNumberOfDaysInActualMonth()
{
    int days=0;
    for (int i=0; i<11; i++)
    {
        cout << "i date[i]: " << i << " " << date[i] << endl;
    }

    string month="", year="";
    for (int k=5; k<7; k++)
    {
        month += date[k];
    }

    for (int j=0; j<4; j++)
    {
        year +=date[j];
    }
    cout << "month: " << month << endl;
    int monthInt = AuxiliaryMethods::convertStringToInteger(month);
    int yearInt = AuxiliaryMethods::convertStringToInteger(year);
    cout << "monthInt: " << monthInt << endl;
    cout << "yearInt: " << yearInt << endl;
    if (monthInt <= 7 && monthInt%2 != 0)
    {
        days = 31;
    }
    else if (monthInt <= 7 && monthInt%2 == 0)
    {
        if (monthInt ==2)
        {
            if(yearInt%4==0 && yearInt%100!=0)
            {
                days = 29;
            }
            else
            {
                days = 28;
            }
        }
        else
        {
           days = 30;
        }
    }
    else if (monthInt >7 && monthInt%2 == 0)
    {
        days = 31;
    }
    else if (monthInt >7 && monthInt%2 != 0)
    {
        days = 30;
    }
    return days;
}
/*void DateManager:: getDateFromTheUser()
{
//    char dateFromUser[11];
    cout << "Please type in the date in 'yyyy-mm-dd' format" << endl;
    cin.sync();
//    date[11]
    cin >> date;
    return date;
//    setDate(dateFromUser[11]);
//    return date[11];
//    string dateFromUser = AuxiliaryMethods::
}*/
