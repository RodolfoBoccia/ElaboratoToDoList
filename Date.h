//
// Created by Notebook on 10/09/2021.
//

#ifndef ELABORATOTODOLIST_DATE_H
#define ELABORATOTODOLIST_DATE_H

#include "iostream"

class Date {
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        validityDate(d, m, y);
    }

    bool isLeap(const int& year) const;

    int daysOfMonth(const int& month, const int& year) const;

    void setDay(int d) {
        Date::day = d;
    }

    void setMonth(int m) {
        Date::month = m;
    }

    void setYear(int y) {
        Date::year = y;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

private:
    bool validityDate(const int& day, const int& month, const int& year) const;

    int day;
    int month;
    int year;
};


#endif //ELABORATOTODOLIST_DATE_H
