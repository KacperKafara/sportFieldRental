//
// Created by student on 04.06.2022.
//

#ifndef SPORTSFIELDRENTAL_DATE_H
#define SPORTSFIELDRENTAL_DATE_H

#include <ctime>
#include "string"
#include "typedefs.h"
#include <iostream>

using std::cout;
using std::endl;

struct Date{
    int year=-1;
    int month=-1;
    int day=-1;
    int hour=-1;
    int minute=-1;

    Date(int year, int month, int day, int hour, int minute) : year(year), month(month), day(day), hour(hour),
                                                               minute(minute){
        if (isValidDate()==false){
            setTodayDate();
            cout<<"ustawiono date na "+getInfo()<<endl;
        }
    }

    bool operator>(const datePtr date) const{

        if (year>date->year) {
            return true;
        }

        if (month>date->month) {
            return true;
        }

        if (day>date->day) {
            return true;
        }

        if(hour>date->hour) {
            return true;
        }

        if (minute>date->minute) {
            return true;
        }

        return false;
    }

    void operator=(const Date& date) {

        year=date.year;
        month=date.month;
        day=date.day;
        hour=date.hour;
        minute=date.minute;
    }

    bool isValidDate(){

        if (year<0)
        {
            return false;
        }

        if (month<1 or month>12)
        {
            return false;
        }

        if (day<1 or day>31)
        {
            return false;
        }

        if (hour<0 or hour>23)
        {
            return false;
        }

        if (minute<0 or minute>59)
        {
            return false;
        }

        return true;
    }

    void setTodayDate()
    {
        std::time_t current=std::time(0);
        std::tm* now = std::localtime(&current);
        year=now->tm_year+1900;
        month=now->tm_mon+1;
        day=now->tm_mday;
        hour=now->tm_hour;
        minute=now->tm_min;
    }

    std::string getInfo()
    {
        std::string hourMark;
        if (hour<10){
            hourMark="0"+std::to_string(hour);
        }
        else{
            hourMark=std::to_string(hour);
        }

        std::string minuteMark;
        if (minute<10){
            minuteMark="0"+std::to_string(minute);
        }
        else{
            minuteMark=std::to_string(minute);
        }


        return std::to_string(day)+"."+std::to_string(month)+"."+std::to_string(year)+" "+hourMark+":"+minuteMark;
    }
};

#endif //SPORTSFIELDRENTAL_DATE_H
