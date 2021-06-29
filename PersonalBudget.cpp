#include <iostream>
#include "PersonalBudget.h"
void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}
void PersonalBudget::userLoggingIn()
{
    userManager.userLoggingIn();
    incomeAndExpenseManager=new IncomeAndExpenseManager(INCOMES_FILE_NAME,EXPENSES_FILE_NAME,userManager.getLoggedUserID());
    incomeAndExpenseManager->uploadExpensesFromFile();
    incomeAndExpenseManager->uploadIncomesFromFile();
}
void PersonalBudget::userLoggingOut()
{
    userManager.userLoggingOut();
    delete incomeAndExpenseManager;
    incomeAndExpenseManager=NULL;
}
void PersonalBudget::userChangePassword()
{
    userManager.userChangePassword();
}
void PersonalBudget::addIncome()
{
    incomeAndExpenseManager->addIncome();
}
void PersonalBudget::addExpense()
{
    incomeAndExpenseManager->addExpense();
}
void PersonalBudget::showCurrentMonthBalance()
{
    incomeAndExpenseManager->showCurrentMonthBalance();
}
void PersonalBudget::showPreviousMonthBalance()
{
    incomeAndExpenseManager->showPreviousMonthBalance();
}
void PersonalBudget::showAll()
{
    incomeAndExpenseManager->showAll();
}
void PersonalBudget::showSelectedPeriodBalance()
{
    incomeAndExpenseManager->showSelectedPeriodBalance();
}
bool PersonalBudget::isUserLoggedIn()
{
    if(userManager.getLoggedUserID()!=0)
        return true;
    else
        return false;
}
char PersonalBudget::chooseMainMenuOption()
{
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = getChar();
    return choice;
}
char PersonalBudget::getChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);
        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
char PersonalBudget::chooseUserMenuOption()
{
    char choice;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bie¿¹cego miesi¹ca" << endl;
    cout << "4. Bilans z poprzedniego miesi¹ca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = getChar();
    return choice;
}
