#include <iostream>
#include "IncomesFile.h"
void IncomesFile::addIncome(Income income)
{
    if(!doesFileExist())
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        lastID=0;
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    lastID+=1;
    xml.AddElem("ID", lastID);
    xml.AddElem("date", DataManager::convertToFile(income.getDate()));
    xml.AddElem("describe", income.getDescribe());
    xml.AddElem("userID", income.getUserID());
    ostringstream strs;

    strs<<income.getAmount();
    xml.AddElem("amount", strs.str());

    xml.Save(FILE_NAME);
}
vector <Income> IncomesFile::uploadIncomesFromFile(int loggedUserID)
{
    vector <Income> incomes;
    Income income;
    if(doesFileExist())
    {
        while ( xml.FindElem("Incomes") )
        {
            xml.IntoElem();
            while (xml.FindElem("Income"))
            {
                xml.IntoElem();
                xml.FindElem("ID");
                income.setID(atoi(MCD_2PCSZ(xml.GetData())));
                lastID=income.getID();
                xml.FindElem("date");
                income.setDate(DataManager::convertToVector((xml.GetData())));
                xml.FindElem("describe");
                income.setDescribe(xml.GetData());
                xml.FindElem("userID");
                income.setUserID(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("amount");
                income.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                if(income.getUserID()==loggedUserID)
                {
                    incomes.push_back(income);
                }
                xml.OutOfElem();
            }
        }
    }
    return incomes;
}
