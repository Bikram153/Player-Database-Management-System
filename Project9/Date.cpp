#include "Date.h"
int Date::getYear() const {
    return year;
}
int Date::getDay() const {
    return day;
}
int Date::getMonth() const {
    return month;
}
void Date::setDay(int d) {
    try {
        if (d >= 1 && d <= 31) {
            day = d;
        }
        else {
            throw std::out_of_range("Invalid Date");
        }
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}
void Date::setMonth(int m) {

    try {
        if (m >= 1 && m <= 12) {
            month = m;
        }
        else {
            throw std::out_of_range("Invalid Month");
        }
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}
void Date::setYear(int y) {
    year = y;
}
void Date::Display() {
    std::cout << "Day - " << day << " Month - " << month << " Year - " << year << std::endl;
}
Date Date::operator+(int months) const {
    Date result = *this;
    result.month += months;

    if (result.month > 12) {
        result.year += result.month / 12;
        result.month %= 12;
    }

    return result;
}




