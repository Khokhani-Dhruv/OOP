#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date {

private:
    int year;
    int month;
    int date;

    static int const DAYS_MONTH[];

    static const int JANUARY = 1;
    static const int FEBRUARY = 2;
    static const int DECEMBER = 12;

public:
    Date();
    Date(int aYear, int aMonth, int aDate);
    int getYear();
    int getMonth();
    int getDate();
    Date addDays(int n);
    Date operator+(int n);
    int daysFrom(const Date& other);
    int operator-(const Date& other);
    int compareTo(const Date& other);
    //return -1 if <, +1 if >, 0 if ==

    //optionally you may also overload operators
    // <, <=, ==, !=, >=, >

    Date nextDay();
    Date previousDay();
    static int daysInMonth(int year, int month);
    static bool isLeapYear(int year);

};

#endif // DATE_H_INCLUDED

