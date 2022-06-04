//
// Created by student on 04.06.2022.
//

#ifndef SPORTSFIELDRENTAL_DATE_H
#define SPORTSFIELDRENTAL_DATE_H

#include <ctime>

struct Date{
    int year=-1;
    int month=-1;
    int day=-1;
    int hour=-1;
    int minute=-1;

    Date(int year, int month, int day, int hour, int minute) : year(year), month(month), day(day), hour(hour),
                                                               minute(minute) {}

    bool operator<(const Date& date) const{
        bool result=false;

        if (year<=date.year){
            if (month<=date.month){
                if (day<=date.day){
                    if(hour<=date.hour){
                        if (minute<date.minute){
                            result=true;}
                    }
                }
            }
        }

        return result;
    }

    bool operator>(const Date& date) const
    {
        bool result=false;

        if (year>=date.year)
        {
            if (month>=date.month)
            {
                if (day>=date.day)
                {
                    if(hour>=date.hour)
                    {
                        if (minute>date.minute)
                        {
                            result=true;
                        }
                    }
                }
            }
        }

        return result;
    }

    bool operator<=(const Date& date) const
    {
        bool result=false;

        if (year<=date.year)
        {
            if (month<=date.month)
            {
                if (day<=date.day)
                {
                    if(hour<=date.hour)
                    {
                        if (minute<=date.minute)
                        {
                            result=true;
                        }
                    }
                }
            }
        }

        return result;
    }

    bool operator>=(const Date& date) const
    {
        bool result=false;

        if (year>=date.year)
        {
            if (month>=date.month)
            {
                if (day>=date.day)
                {
                    if(hour>=date.hour)
                    {
                        if (minute>=date.minute)
                        {
                            result=true;
                        }
                    }
                }
            }
        }

        return result;
    }

    bool operator==(const Date& date) const
    {
        bool result=false;

        if (year==date.year)
        {
            if (month==date.month)
            {
                if (day==date.day)
                {
                    if(hour==date.hour)
                    {
                        if (minute==date.minute)
                        {
                            result=true;
                        }
                    }
                }
            }
        }

        return result;
    }

    bool isValidDate()
    {
        bool result=true;

        if (year<0)
        {
            result=false;
        }

        if (month<=0 or month>12)
        {
            result=false;
        }

        if (day<=0 or day>31)
        {
            result=false;
        }

        if (hour<0 or hour>=24)
        {
            result=false;
        }

        if (minute<=0 or minute>60)
        {
            result=false;
        }

        return result;
    }

    void setTodayDate()
    {
        std::time_t current=std::time(0);
        std::tm* now = std::localtime(&current);
        year=now->tm_year;
        month=now->tm_mon;
        day=now->tm_mday;
        hour=now->tm_hour;
        minute=now->tm_min;
    }
};

#endif //SPORTSFIELDRENTAL_DATE_H
