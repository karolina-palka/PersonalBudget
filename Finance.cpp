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
void Finance:: setAmount(int newAmount)
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
int Finance:: getAmount()
{
    return amount;
}
string Finance:: getItem()
{
    return item;
}