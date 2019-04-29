#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <tuple>
#include <set>
#include <iomanip>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class Date{
private:
    int year_;
    int month_;
    int day_;
public:
    Date();
    Date(int y, int m, int d);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    void SetYear(int x);
    void SetMonth(int x);
    void SetDay(int x);
    std::string ToEnglish() const;
    inline static const std::set<int> thirtyOneDaysMonths = {1, 3, 5, 7, 8, 10, 12};
};

int MaxDayInMonth(int year, int month);

bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
bool operator < (const Date& lhs, const Date& rhs);

bool IsValidDate(const std::string& str_date);
bool IsLeapYear(int year);

std::ostream& operator << (std::ostream& stream, const Date& date);
std::istream& operator >> (std::istream& stream, Date& date);


#endif