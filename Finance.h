#ifndef FINANCE_H_INCLUDED
#define FINANCE_H_INCLUDED
#include <iostream>

using namespace std;

class Finance
{
    int financeId, userId, amount, date;
    string item, dateStr;
//    char date[11];

public:
    void setFinanceId(int newFinanceId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setDateStr(string newDateStr);
    void setAmount(int newAmount);
    void setItem(string newItem);

    int getFinanceId();
    int getUserId();
    int getDate();
    string getDateStr();
    int getAmount();
    string getItem();
};


#endif // FINANCE_H_INCLUDED
