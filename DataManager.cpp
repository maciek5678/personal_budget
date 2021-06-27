#include <iostream>
#include <sstream>
#include "DataManager.h"
int DataManager:: giveTodayData()
{
        int year,month,day, date;
            time_t now = time(0);
        tm *ltm = localtime(&now);

    year=1900+ ltm->tm_year;

   month=1+ltm->tm_mon;

   day=ltm->tm_mday;


    date=year*10000+month*100+day;
    return date;
}
int DataManager:: insertData()
{

int year,month,day, date;
        string stringDate;
        cout<<"Wprowadz date w formacie rrrr-mm-dd"<<endl;
        cin>>stringDate;
        year=stoi(stringDate.substr(0,4));
        cout<<year<<endl;
        month=stoi(stringDate.substr(5,2));
        cout<<month<<endl;
        day=stoi(stringDate.substr(8,2));
        cout<<day<<endl;
        if(year<2000)
        {
            cout<<"Podaj date z roku co najmniej 2000"<<endl;
        }
        if (month>12)
            {
            cout<<"Niepoprawny miesiac"<<endl;

        }
        if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31)
        {

        }else if((month==4||month==6||month==9||month==11)&&day<=30)
        {

        }else if((month==2)&&(((year%4==0)&&(year%100!=0))||(year%400==0))&&day<=29)
                 {

                 }else if (month==2&&day<=28)
                 {

                 }
                 else
                 {
                     cout<<"data niepoprawna"<<endl;
                 }
                         time_t now = time(0);
        tm *ltm = localtime(&now);
int currentYear, currentMonth;
currentYear=1900+ ltm->tm_year;
currentMonth=1+ltm->tm_mon;
if(year>currentYear||(year==currentYear)&&(month>currentMonth))
{
  cout<<"Data przyszla. Podaj inna"<<endl;
}
date=year*10000+month*100+day;
    return date;
}
 void DataManager::changeDateFormat(int date)
 {
     int year=0;
     int month=0;
     int day=0;
     year=date/10000;
     month=(date-(year*10000))/100;
     day=date-(year*100+month)*100;
     string zeroDay="";
     string zeroMonth="";
     if(day<10)
     {
         zeroDay="0";
     }
     if(month<10)
     {
         zeroMonth="0";
     }
 cout<<year<<"-"<<zeroMonth<<month<<"-"<<zeroDay<<day<<endl;

 }
int DataManager::showCurrentMonth()
{

    time_t now = time(0);
        tm *ltm = localtime(&now);
       int currentYear=1900+ ltm->tm_year;
int currentMonth=1+ltm->tm_mon;
int currentPeriod=0;
if(currentMonth==13)
{
    currentYear+=1;
    currentMonth=1;
}
currentPeriod=currentYear*100+currentMonth;
return currentPeriod;
}
 int DataManager::showPreviousMonth()
{
      time_t now = time(0);
        tm *ltm = localtime(&now);
       int currentYear=1900+ ltm->tm_year;
int currentMonth=1+ltm->tm_mon;
int currentPeriod=0;
if(currentMonth==12){
    currentYear=currentYear-1;
    currentMonth=13;}
currentPeriod=currentYear*100+currentMonth-1;
return currentPeriod;
}
int DataManager::selectedDate()
{
             string stringDate="";
int year=0;
int month=0;
int day=0;
        cin>>stringDate;
        year=stoi(stringDate.substr(0,4));
        cout<<year<<endl;
        month=stoi(stringDate.substr(5,2));
        cout<<month<<endl;
        day=stoi(stringDate.substr(8,2));
        cout<<day<<endl;
        if(year<2000)
        {
            cout<<"Podaj date z roku co najmniej 2000"<<endl;
        }
        if (month>12)
            {
            cout<<"Niepoprawny miesiac"<<endl;

        }
        if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31)
        {

        }else if((month==4||month==6||month==9||month==11)&&day<=30)
        {

        }else if((month==2)&&(((year%4==0)&&(year%100!=0))||(year%400==0))&&day<=29)
                 {

                 }else if (month==2&&day<=28)
                 {

                 }
                 else
                 {
                     cout<<"data niepoprawna"<<endl;
                 }
                         time_t now = time(0);
        tm *ltm = localtime(&now);


int date=year*10000+month*100+day;
return date;
}
