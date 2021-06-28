#include <iostream>
#include "UserManager.h"
void UserManager::userRegistration()
{
    User user;
    user=getData();



    users.push_back(user);
    usersFile.addUser(user);

}
int UserManager::userLoggingIn()
{
    string login;
    cout<<"Podaj login: ";
    cin>>login;
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {


        if(itr->getLogin()==login)
        {

            string password;

            for (int tryCounter = 3; tryCounter > 0; tryCounter--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tryCounter << ": ";
                cin>>password;

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserID=itr -> getUserID();

                    return loggedUserID;
                }
            }

            break;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
bool UserManager::doesLoginExist( string login)
{
    for(int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout<<endl<<"Istnieje uzytkownik o takim loginie."<<endl;
            return true;
        }
    }
    return false;

}
void UserManager::userLoggingOut()
{
    loggedUserID=0;
}
void UserManager::userChangePassword()
{
    string password;
    cout<<"Podaj nowe haslo: ";
    cin>>password;
    for(int i=0; i<=users.size(); i++)
        if (users[i].getUserID()==loggedUserID)
            users[i].setPassword(password);
    usersFile.changePassword(loggedUserID,password);


}
void UserManager::uploadUsersFromFile()
{
    usersFile.uploadUsersFromFile();
}
int UserManager::getLoggedUserID()
{

    return loggedUserID;
}
User UserManager::getData()
{
    User user;
    if(users.empty())
        user.setUserID(1);
    else
        user.setUserID(users.back().getUserID()+1);
    string name;
    cout<<"Podaj imie: ";
    cin>>name;
    user.setName(name);
    string surname;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    user.setSurname(surname);

    string login;
    do
    {
        vector <User>::iterator itr = users.begin();
        cout << "Podaj login: ";
        cin>>login;
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin()) == true);
    string password;
    cout<<"Podaj haslo: ";
    cin>>password;
    user.setPassword(password);
    return user;
}
