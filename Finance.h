#ifndef FINANCE_H_INCLUDED
#define FINANCE_H_INCLUDED
#include <iostream>

using namespace std;

class Finance
{
    int financeId, userId, date, amount;
    string item;

public:
    void setFinanceId(int newFinanceId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setAmount(int newAmount);
    void setItem(string newItem);

    int getFinanceId();
    int getUserId();
    int getDate();
    int getAmount();
    string getItem();
};


#endif // FINANCE_H_INCLUDED
