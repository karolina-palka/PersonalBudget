#include "DateManager.h"

int DateManager:: convertStringDateToIntDate(string dateToBeConverted)
{
    string dateToConvert="";
    int dateInt=0;

    for (int i=2; i<11; i++)
    {
        if(dateToBeConverted[i]!='-')
        {
            dateToConvert += dateToBeConverted[i];
        }
    }
    dateInt = AuxiliaryMethods::convertStringToInteger(dateToConvert);

    return dateInt;
}
bool DateManager:: isDateCorrect(string dateToBeChecked)
{
    string daysFromDate = "", actualDate="";
    int actualDateInt;
    int dateToBeCheckedInt = convertStringDateToIntDate(dateToBeChecked);

    for (int j=4; j<8; j+=3)
    {
        if(dateToBeChecked[j]!= '-')
        {
            cout << "Incorrect format. Please type in again." << endl;
            return false;
        }
    }
    actualDate=getActualDateFromTheSystem();
    actualDateInt = convertStringDateToIntDate(actualDate);

    if (dateToBeCheckedInt >= 101 && dateToBeCheckedInt <= actualDateInt)
    {
        int daysOfActualMonth = getNumberOfDaysInActualMonth(dateToBeChecked);

        for (int i=8; i<10; i++)
        {
            daysFromDate += dateToBeChecked[i];
        }
        int daysFromDateInt = AuxiliaryMethods::convertStringToInteger(daysFromDate);

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

    return actualDate;
}
int DateManager:: getNumberOfDaysInActualMonth(string date)
{
    int days=0;

    string month="", year="";
    for (int k=5; k<7; k++)
    {
        month += date[k];
    }

    for (int j=0; j<4; j++)
    {
        year +=date[j];
    }

    int monthInt = AuxiliaryMethods::convertStringToInteger(month);
    int yearInt = AuxiliaryMethods::convertStringToInteger(year);

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
int DateManager:: getDateFromTheUser()
{
    int dateInt;
    string dateStr;

    dateStr = AuxiliaryMethods::getTheLine();
    dateInt = convertStringDateToIntDate(dateStr);

    while (isDateCorrect(dateStr)==false)
    {
        dateStr = AuxiliaryMethods::getTheLine();
        dateInt = convertStringDateToIntDate(dateStr);
    }
    return dateInt;
}

