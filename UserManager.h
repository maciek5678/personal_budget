#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
using namespace std;

class UserManager
{
    int loggedUserID;
    vector <User> users;
    UsersFile usersFile;
public:
    UserManager(string usersFileName)
        :usersFile(usersFileName)
    {
        loggedUserID=0;
        users=usersFile.uploadUsersFromFile();
    }
    void userRegistration();
    int userLoggingIn();
    bool doesLoginExist( string login);
    void userLoggingOut();
    void userChangePassword();
    void uploadUsersFromFile();
    int getLoggedUserID();
    User getData();
};
