#include <iostream>
#include "User.h"

 void User::setUserID(int newID)
 {
     userID=newID;
 }
    void User::setName(string newName)
    {
name=newName;
    }
void User::setSurname(string newSurname){
surname=newSurname;
}
void User::setLogin(string newLogin)
{
login=newLogin;
}
void User::setPassword(string newPassword){
password=newPassword;
}
string User::getName()
{
return name;
}
string User::getSurname(){
return surname;
}
string User::getLogin()
{
return login;
}
string User::getPassword(){
return password;
}
int User:: getUserID()
{
    return userID;
}
