#ifndef FINANCE_H
#define FINANCE_H
#include <iostream>

using namespace std;
class Finance
{
    int id;
    string describe;
    int userID;
    double amount;
    int date;
public:
    void setDate(int newDate);
    void setDescribe(string newDescribe);
    void setUserID(int newUserID);
    void setID(int newID);
    void setAmount(double newAmount);
    int getDate();
    string getDescribe();
    int getUserID();
    double getAmount();
    int getID();
};
#endif
