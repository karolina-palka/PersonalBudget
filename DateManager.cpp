#include "DateManager.h"

void DateManager:: setDate(char newDate[11])
{
    for (int i=0; i<11; i++)
    {
        date[i] = newDate[i];
    }
//    date = newDate;
    cout << "date: " << date << endl;
}
char DateManager:: getDate()
{
    return date[11];
}
int DateManager:: convertCharDateToIntDate(char dateToBeConverted[11])
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
    if (dateToBeChecked >= 101 && dateToBeChecked <= 210524)
        return true;
    else
    {
        cout << "The date you typed in is incorrect. Please type again." << endl;
    }
        return false;
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
