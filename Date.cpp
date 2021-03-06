//
// Created by Notebook on 10/09/2021.
//

#include "Date.h"

bool Date::isLeap(const int& year) const {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true; }
    else return false;
}

int Date::daysOfMonth(const int& month, const int& year) const {
    switch (month) {
        case 2:
            if (isLeap(year)) return 29;
            else return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

bool Date::validityDate(const int& day, const int& month, const int& year) const {
    if (year >= 1900 && year < 2200 && month > 0 && month < 13 && day > 0 && day <= daysOfMonth(month, year)){
        return true; }
    else throw (std::out_of_range) "Data non valida";;
}