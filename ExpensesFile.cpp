#include <iostream>
#include "ExpensesFile.h"
void ExpensesFile::addExpense(Expence expense)
{
    if(!doesFileExist())
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        lastID=0;
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    lastID+=1;
    xml.AddElem("ID", lastID);
    xml.AddElem("date", DataManager::convertToFile(expense.getDate()));
    xml.AddElem("describe", expense.getDescribe());
    xml.AddElem("userID", expense.getUserID());
    ostringstream strs;

    strs<<expense.getAmount();
    xml.AddElem("amount", strs.str());

    xml.Save(FILE_NAME);
}
vector <Expence> ExpensesFile::uploadExpensesFromFile(int loggedUserID)
{

    vector <Expence> expences;
    Expence expence;
    if(doesFileExist())
    {
        while ( xml.FindElem("Expenses") )
        {
            xml.IntoElem();
            while (xml.FindElem("Expense"))
            {
                xml.IntoElem();
                xml.FindElem("ID");
                expence.setID(atoi(MCD_2PCSZ(xml.GetData())));
                lastID=expence.getID();
                xml.FindElem("date");
                expence.setDate(DataManager::convertToVector((xml.GetData())));

                xml.FindElem("describe");
                expence.setDescribe(xml.GetData());

                xml.FindElem("userID");
                expence.setUserID(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem("amount");

                expence.setAmount(atof(MCD_2PCSZ(xml.GetData())));

                if(expence.getUserID()==loggedUserID)
                {
                    expences.push_back(expence);
                }
                xml.OutOfElem();
            }
        }
    }
    return expences;
}
