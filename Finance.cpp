#include "Finance.h"

void Finance:: setFinanceId(int newFinanceId)
{
    financeId = newFinanceId;
}
void Finance:: setUserId(int newUserId)
{
    userId = newUserId;
}
void Finance:: setDate(int newDate)
{
    date = newDate;
}
void Finance:: setDateStr(string newDateStr)
{
    dateStr = newDateStr;
}
void Finance:: setAmount(double newAmount)
{
    amount = newAmount;
}
void Finance:: setItem(string newItem)
{
    item = newItem;
}
int Finance:: getFinanceId()
{
    return financeId;
}
int Finance:: getUserId()
{
    return userId;
}
int Finance:: getDate()
{
    return date;
}
string Finance:: getDateStr()
{
    return dateStr;
}
double Finance:: getAmount()
{
    return amount;
}
string Finance:: getItem()
{
    return item;
}
