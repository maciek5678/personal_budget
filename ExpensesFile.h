#include <iostream>
#include <vector>
#include <sstream>
#include "XMLFile.h"
#include "Expence.h"
#include "DataManager.h"
using namespace std;
class ExpensesFile:public XMLFile
{
public:
    ExpensesFile(string expensesFileName)
        : XMLFile(expensesFileName)
    {
        lastID=0;
    };
    void addExpense(Expence expence);
    vector <Expence> uploadExpensesFromFile(int loggedUserID);
};
