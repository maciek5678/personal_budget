#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>
#include <string>
#include "UsersFile.h"
#include "XMLFile.h"
#include "User.h"
#include "Markup.h"
using namespace std;
class UsersFile: public XMLFile{
int lastUserID;
public:
    UsersFile(string usersFileName)
    : XMLFile(usersFileName){};
void addUser(User user);
vector <User> uploadUsersFromFile();
void changePassword(int loggedUserID, string password);
};
#endif

