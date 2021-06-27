#include <iostream>
#include "PersonalBudget.h"
using namespace std;

int main()
{
PersonalBudget personalBudget("users.xml", "incomes.xml", "expences.xml");

        while (true)
    {
        if (personalBudget.isUserLoggedIn()==false)
        {
            char choose;
            choose = personalBudget.chooseMainMenuOption();

            switch (choose)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLoggingIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else{
                char choose;
                    choose = personalBudget.chooseUserMenuOption();

            switch (choose)
            {
            case '1':
        personalBudget.addIncome();
                break;
            case '2':
        personalBudget.addExpense();
                break;
            case '3':
        personalBudget.showCurrentMonthBalance();
                break;
            case '4':
        personalBudget.showPreviousMonthBalance();
                break;
            case '5':
        personalBudget.showSelectedPeriodBalance();
                break;
            case '6':
        personalBudget.userChangePassword();
                break;
            case '7':
    personalBudget.userLoggingOut();
                break;

            }
        }
    }

    return 0;
}
