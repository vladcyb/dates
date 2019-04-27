#include <iostream>
#include <tuple>
#include <set>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

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
    string ToRussian() const;
    inline static const set<int> thirtyOneDaysMonths = {1, 3, 5, 7, 8, 10, 12};
};

int MaxDayInMonth(int year, int month);

bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
bool operator < (const Date& lhs, const Date& rhs);

bool IsValidDate(const Date& date);
bool IsLeapYear(int year);

ostream& operator << (ostream& stream, const Date& date);
istream& operator >> (istream& stream, Date& date);