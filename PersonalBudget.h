#include <iostream>
#include "UserManager.h"
#include "IncomeAndExpenseManager.h"
using namespace std;

class PersonalBudget
{
UserManager userManager;
IncomeAndExpenseManager *incomeAndExpenseManager;
const string INCOMES_FILE_NAME;
const string EXPENSES_FILE_NAME;
public:
    PersonalBudget(string usersFileName,string incomesFileName,string expensesFileName )
    :userManager(usersFileName),INCOMES_FILE_NAME(incomesFileName),EXPENSES_FILE_NAME(expensesFileName)
    {
userManager.uploadUsersFromFile();
incomeAndExpenseManager=NULL;
    }
    void userRegistration();
    void userLoggingIn();
    void userLoggingOut();
    void userChangePassword();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();
   void showAll();
   bool isUserLoggedIn();
   char getChar();
   char chooseMainMenuOption();
   char chooseUserMenuOption();
};
