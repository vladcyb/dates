#include "date.h"

int Date::GetYear() const {
    return year_;
}

int Date::GetMonth() const {
    return month_;
}

int Date::GetDay() const {
    return day_;
}

void Date::SetYear(int x){
    year_ = x;
}

void Date::SetMonth(int x){
    month_ = x;
}

void Date::SetDay(int x){
    day_ = x;
}

Date::Date(){

}

Date::Date(int y, int m, int d)
: year_(y)
, month_(m)
, day_(d) {
}

auto GetRankDate(const Date& date){
    return make_tuple(date.GetYear(), date.GetMonth(), date.GetDay());
}

bool operator == (const Date& lhs, const Date& rhs){
    return GetRankDate(lhs) == GetRankDate(rhs);
}

bool operator != (const Date& lhs, const Date& rhs){
    return GetRankDate(lhs) != GetRankDate(rhs);
}

bool operator < (const Date& lhs, const Date& rhs){
    return GetRankDate(lhs) < GetRankDate(rhs);
}

bool IsLeapYear(int year){
    if (year % 400 == 0){
        return true;
    }else if (year % 100 == 0){
        return false;
    }else if (year % 4 == 0){
        return true;
    }else{
        return false;
    }
    return true;
}

int MaxDayInMonth(int year, int month){
    if (month == 2){
        if (IsLeapYear(year)){
            return 29;
        }else{
            return 28;
        }
    }else if (Date::thirtyOneDaysMonths.find(month) != Date::thirtyOneDaysMonths.end()){
        return 31;
    }else{
        return 30;
    }
}

string Date::ToRussian() const {
    vector<string> month_names = {
        "января",
        "февраля",
        "марта",
        "апреля",
        "мая",
        "июня",
        "июля",
        "августа",
        "сентября",
        "октября",
        "ноября",
        "декабря"
    };
    string month_name = month_names[month_ - 1];
    stringstream ss;
    ss << day_ << ' ' << month_name << ' ' << year_;
    return ss.str();
}


bool IsValidDate(const Date& date){
    int year = date.GetYear();
    int month = date.GetMonth();
    int day = date.GetDay();
    int max_day = MaxDayInMonth(year, month);
    if (month < 1 || month > 12){
        return false;
    }
    if (day < 1 || day > max_day){
        return false;
    }
    return true;
}

ostream& operator << (ostream& stream, const Date& date){
    stream << setfill('0');
    return stream << setw(4) << date.GetYear() << '-' << setw(2)
        << date.GetMonth() << '-' << setw(2) << date.GetDay();
}

istream& operator >> (istream& stream, Date& date){
    int year, month, day;
    stream >> year;
    stream.ignore(1);
    stream >> month;
    stream.ignore(1);
    stream >> day;
    date.SetYear(year);
    date.SetMonth(month);
    date.SetDay(day);
    return stream;
}