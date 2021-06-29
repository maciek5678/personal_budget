#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
class User
{
    int userID;
    string name;
    string surname;
    string login;
    string password;
public:
    void setUserID(int newID);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
    int getUserID();
};
#endif
