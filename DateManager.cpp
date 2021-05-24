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
int DateManager:: convertCharDateToIntDate(string dateToBeConverted)
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
