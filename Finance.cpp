#include <iostream>
#include "Finance.h"
void Finance::setDate(int newDate)
{
    date=newDate;
}
void Finance::setDescribe(string newDescribe)
{
    describe=newDescribe;
}
void Finance::setUserID(int newUserID)
{
    userID=newUserID;
}
void Finance::setID(int newID)
{
    id=newID;
}
void Finance::setAmount(double newAmount)
{
    amount=newAmount;
}
int Finance::getDate()
{
    return date;
}
string Finance::getDescribe()
{
    return describe;
}
int Finance::getUserID()
{
    return userID;
}

double Finance::getAmount()
{
    return amount;
}
int Finance::getID()
{
    return id;
}
