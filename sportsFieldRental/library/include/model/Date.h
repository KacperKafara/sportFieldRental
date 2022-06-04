//
// Created by student on 04.06.2022.
//

#ifndef SPORTSFIELDRENTAL_DATE_H
#define SPORTSFIELDRENTAL_DATE_H

struct Date{
    int year=-1;
    int month=-1;
    int day=-1;
    int hour=-1;
    int minute=-1;

    Date(int year, int month, int day, int hour, int minute) : year(year), month(month), day(day), hour(hour),
                                                               minute(minute) {}

    bool operator<(const Date& date) const
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
                        if (minute<date.minute)
                        {
                            result=true;
                        }
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
        bool result=false;

        if (year<0 or month<0 or day<0 or hour<0 or minute<0)
        {
            result=false;
        }
        else
        {
            result=true;
        }

        return result;
    }
};

#endif //SPORTSFIELDRENTAL_DATE_H
