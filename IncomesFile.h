#include <iostream>
#include <vector>
#include <sstream>
#include "XMLFile.h"
#include "Income.h"
#include "DataManager.h"
using namespace std;
class IncomesFile:public XMLFile
{
public:
    IncomesFile(string incomesFileName)
        : XMLFile(incomesFileName)
    {
        lastID=0;
    };
    void addIncome(Income income);
    vector <Income> uploadIncomesFromFile(int loggedUserID);
};
