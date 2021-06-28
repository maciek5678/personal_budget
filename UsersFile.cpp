#include <iostream>
#include "UsersFile.h"
void UsersFile::addUser(User user)
{
    if(!doesFileExist())
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserID());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(FILE_NAME);
}
vector <User> UsersFile::uploadUsersFromFile()
{
    vector <User> users;
    User user;
    if(doesFileExist())
    {
        while ( xml.FindElem("Users") )
        {
            xml.IntoElem();
            while (xml.FindElem("User"))
            {
                xml.IntoElem();
                xml.FindElem("UserId");
                user.setUserID(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem("Name");
                user.setName(xml.GetData());

                xml.FindElem("Surname");
                user.setSurname(xml.GetData());

                xml.FindElem("Login");

                user.setLogin(xml.GetData());

                xml.FindElem("Password");

                user.setPassword(xml.GetData());

                users.push_back(user);
                xml.OutOfElem();
            }
        }
    }
    return users;
}
void UsersFile::changePassword(int loggedUserID, string password)
{
    if(doesFileExist())
    {




        while ( xml.FindElem("Users") )
        {
            xml.IntoElem();
            while (xml.FindElem("User"))
            {
                xml.IntoElem();
                xml.FindElem("UserId");
                int IdZPliku=atoi(MCD_2PCSZ(xml.GetData()));
                if(IdZPliku!=loggedUserID)
                {
                    xml.OutOfElem();
                }
                if(IdZPliku==loggedUserID)
                {
                    xml.FindElem("Password");
                    xml.RemoveElem();
                    xml.AddElem("Password", password);
                    xml.Save(FILE_NAME);

                }

            }
        }

    }
}
