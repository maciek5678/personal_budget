#include <iostream>
#include <ctime>
#include <string>
#include "IncomeAndExpenseManager.h"
void IncomeAndExpenseManager::addIncome()
{

    Income income;
    int date=0;


    if(todayIncome()==true)
    {

    date=DataManager::giveTodayData();

    }else
    {
        date=DataManager::insertData();
    }

income.setUserID(loggedUserID);
income.setDate(date);
income.setDescribe(setDescribe());


income.setAmount(setAmount());
incomes.push_back(income);
    incomesFile.addIncome(income);

}
void IncomeAndExpenseManager::addExpense()
{
    Expence expense;
    int date=0;


    if(todayExpense()==true)
    {
    date=DataManager::giveTodayData();



    }else if(todayExpense()==false)
    {
date=DataManager::insertData();
    }

expense.setUserID(loggedUserID);
expense.setDate(date);

    expense.setDescribe(setDescribe());


expense.setAmount(setAmount());
    expensesFile.addExpense(expense);
expences.push_back(expense);
}

void IncomeAndExpenseManager::sortVectorIncome()
{

sort(incomes.begin(),incomes.end(),[] ( Income &i1, Income &i2){
    return i1.getDate()<i2.getDate();
     });

}
void IncomeAndExpenseManager::sortVectorExpense()
{

sort(expences.begin(),expences.end(),[] ( Expence &e1, Expence &e2){
    return e1.getDate()<e2.getDate();
     });

}
void IncomeAndExpenseManager::showCurrentMonthBalance()
{
int currentPeriod=0;
double balance=0;
currentPeriod=DataManager::showCurrentMonth();
sortVectorIncome();
cout<<endl<<"Przychody: "<<endl;
for(vector <Income> ::iterator itr=incomes.begin();itr!=incomes.end();itr++)
{
    if(itr->getDate()/100==currentPeriod)
    {
showIncomeDetails(*itr);

balance+=itr->getAmount();
    }

}
cout<<endl<<"Wydatki: "<<endl;
sortVectorExpense();
for(vector <Expence> ::iterator itr=expences.begin();itr!=expences.end();itr++)
{
    if(itr->getDate()/100==currentPeriod)
    {
showExpenseDetails(*itr);
balance-=itr->getAmount();

    }

}
cout<<endl<<"------------"<<endl;
cout<<"Bilans: "<<balance<<endl;
system("pause");
}
void IncomeAndExpenseManager::showPreviousMonthBalance()
{
    double balance=0;
int currentPeriod=0;
currentPeriod=DataManager::showPreviousMonth();
sortVectorIncome();
for(vector <Income> ::iterator itr=incomes.begin();itr!=incomes.end();itr++)
{
    if(itr->getDate()/100==currentPeriod)
    {
showIncomeDetails(*itr);
balance+=itr->getAmount();
    }

}
sortVectorExpense();
for(vector <Expence> ::iterator itr=expences.begin();itr!=expences.end();itr++)
{
    if(itr->getDate()/100==currentPeriod)
    {
 showExpenseDetails(*itr);
balance-=itr->getAmount();
cout<<itr->getAmount()<<endl;
    }

}
cout<<endl<<"------------"<<endl;
cout<<"Bilans: "<<balance<<endl;
system("pause");

}

void IncomeAndExpenseManager::showSelectedPeriodBalance()
{
       int beginDate=0;

        int endDate=0;
cout<<"Wprowadz date początkowa w formacie rrrr-mm-dd"<<endl;
beginDate=DataManager::selectedDate();


        cout<<"Wprowadz date koncowa w formacie rrrr-mm-dd"<<endl;
endDate=DataManager::selectedDate();




double balance=0;
sortVectorIncome();
cout<<endl<<"Przychody: "<<endl;
    for(vector <Income> ::iterator itr=incomes.begin();itr!=incomes.end();itr++)
{
    if(beginDate<=itr->getDate() &&endDate>=itr->getDate())
    {


  showIncomeDetails(*itr);
  balance+=itr->getAmount();
    }

}
sortVectorExpense();
cout<<endl<<"Wydatki: "<<endl;
    for(vector <Expence> ::iterator itr=expences.begin();itr!=expences.end();itr++)
{
    if(beginDate<=itr->getDate() &&endDate>=itr->getDate())
    {
  showExpenseDetails(*itr);
  balance-=itr->getAmount();
    }

}
cout<<endl<<"------------"<<endl;
cout<<"Bilans: "<<balance<<endl;
system("pause");
}
void IncomeAndExpenseManager::showAll()
{

    for(vector <Expence> ::iterator itr=expences.begin();itr!=expences.end();itr++)
{
         cout<<"Data: ";
        cout<<itr->getDate()<<endl;
        cout<<"Opis: ";
        cout<<itr->getDescribe()<<endl;
        cout<<"UserID: ";
        cout<<itr->getUserID()<<endl;
        cout<<"Wartosc: ";
        cout<<itr->getAmount()<<endl;

}
}

void IncomeAndExpenseManager::uploadIncomesFromFile()
{
    incomesFile.uploadIncomesFromFile(loggedUserID);
}
void IncomeAndExpenseManager::uploadExpensesFromFile()
{
    expensesFile.uploadExpensesFromFile(loggedUserID);
}
bool IncomeAndExpenseManager::todayIncome()
{
cout<<"Czy przychod jest dzisiejszy? Jeœli tak wcisnij t oraz enter"<<endl;

    char sign=getchar();
    if(sign=='t')
        return true;
   else
        return false;
}
string IncomeAndExpenseManager::setDescribe()
{
         string describe;
    cout<<"podaj opis:"<<endl;
    getchar();
    getline (cin,describe);
    return describe;
}
double IncomeAndExpenseManager::setAmount()
{
        string amount;
    cout<<"podaj wartosc:"<<endl;
    cin>>amount;
   for(int i=0;i<amount.length();i++)
    if(amount[i]==',')
    amount[i]='.';
double numAmount=stod(amount);
return numAmount;
}
bool IncomeAndExpenseManager::todayExpense()
{
        cout<<"Czy wydatek jest dzisiejszy? Jesli tak wcisnij t oraz enter."<<endl;

    char sign=getchar();
        if(sign=='t')
        return true;
   else
        return false;
}
void IncomeAndExpenseManager::showIncomeDetails(Income income)
{
            cout<<endl;
        cout<<"data: ";
        DataManager::changeDateFormat(income.getDate());
        cout<<"Opis: ";
        cout<<income.getDescribe()<<endl;
        cout<<"UserID: ";
        cout<<income.getUserID()<<endl;
        cout<<"Wartosc: ";
        cout<<income.getAmount()<<endl;
}
void IncomeAndExpenseManager::showExpenseDetails(Expence expense)
{
            cout<<endl;
        cout<<"data: ";
        DataManager::changeDateFormat(expense.getDate());
        cout<<"opis: ";
        cout<<expense.getDescribe()<<endl;
        cout<<"UserID: ";
        cout<<expense.getUserID()<<endl;
        cout<<"Wartosc: ";
        cout<<expense.getAmount()<<endl;
}
