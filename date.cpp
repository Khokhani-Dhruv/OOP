#include "date.h"

int const Date::DAYS_MONTH[]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(){
    year = 1990,
    month = 1;
    date = 1;
}

Date::Date(int aYear, int aMonth, int aDate) {
    year = aYear;
    month = aMonth;
    date = aDate;
}

int Date::getYear()  {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDate()  {
    return date;
}

Date Date::addDays(int n)   {
    Date result = *this;
    while (n > 0) {
        result = result.nextDay();
        n--;
    }
    while (n < 0) {
        result = result.previousDay();
        n++;
    }
    return result;
}

int Date::daysFrom(const Date& other) {
    int n = 0;
    Date d = *this;
    while (d.compareTo(other) > 0)   {
        d = d.previousDay();
        n++;
    }
    while (d.compareTo(other) < 0)   {
        d = d.nextDay();
        n--;
    }
    return n;
}

int Date::compareTo(const Date& other)  {
    if (year > other.year) return 1;
    if (year < other.year) return -1;
    if (month > other.month) return 1;
    if (month < other.month) return -1;
    if (date < other.date) return -1;
    return 0;

}

Date Date::nextDay() {
    int y = year;
    int m = month;
    int d = date;

    if (d < daysInMonth(y, m))
        d++;
    else {
        d = 1;
        m++;
        if (m > DECEMBER) {
            m = JANUARY;
            y++;
            if (y == 0)
                y++;
        }
    }
    return Date(y, m, d);
}

Date Date::previousDay() {
    int y = year;
    int m = month;
    int d = date;

    if (d > 1)
        d--;
    else {
        m--;
        if (m < JANUARY) {
            m = DECEMBER;
            y--;
            if (y == 0)
                y--;
        }
        d = daysInMonth(y, m);
    }
    return Date(y, m, d);
}

int Date::daysInMonth(int y, int m) {
    int days = Date::DAYS_MONTH[m - 1];
    if (m == FEBRUARY && isLeapYear(y))
        days++;
    return days;
}

bool Date::isLeapYear(int y) {
    if (y % 4 != 0) return false;
    return (y % 100 != 0) || (y % 400 == 0);
}

