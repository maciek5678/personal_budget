#include <iostream>
#include <vector>
#include <sstream>
#include "XMLFile.h"
#include "Income.h"

using namespace std;
class IncomesFile:public XMLFile
{
public:
    IncomesFile(string incomesFileName)
    : XMLFile(incomesFileName){};
void addIncome(Income income);
vector <Income> uploadIncomesFromFile(int loggedUserID);
};
