#ifndef FINANCE_H_INCLUDED
#define FINANCE_H_INCLUDED
#include <iostream>

using namespace std;

class Finance
{
    int financeId, userId, amount;
    string item;
    char date[11];

public:
    void setFinanceId(int newFinanceId);
    void setUserId(int newUserId);
    void setDate(char newDate[11]);
    void setAmount(int newAmount);
    void setItem(string newItem);

    int getFinanceId();
    int getUserId();
    string getDate();
    int getAmount();
    string getItem();
};


#endif // FINANCE_H_INCLUDED
