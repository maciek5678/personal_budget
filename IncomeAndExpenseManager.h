#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expence.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DataManager.h"
using namespace std;
class IncomeAndExpenseManager
{
    int loggedUserID;
    vector <Income> incomes;
    vector <Expence> expences;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;

public:
    IncomeAndExpenseManager(string incomesFileName,string expensesFileName,int logUserID)
        : incomesFile(incomesFileName),expensesFile(expensesFileName), loggedUserID(logUserID)
    {

        incomes=incomesFile.uploadIncomesFromFile(loggedUserID);
        expences=expensesFile.uploadExpensesFromFile(loggedUserID);

    }


    void addIncome();
    void addExpense();
    void sortVectorIncome();
    void sortVectorExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showAll();
    void uploadIncomesFromFile();
    void uploadExpensesFromFile();
    void showSelectedPeriodBalance();
    bool todayIncome();
    bool todayExpense();
    string setDescribe();
    double setAmount();
    void showIncomeDetails(Income income);
    void showExpenseDetails(Expence expense);

};
