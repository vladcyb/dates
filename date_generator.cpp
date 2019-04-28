#include "date_generator.h"

int DateGenerator::GetRandomYear(){
    return GetRandomInt(1970, 2025);
}
int DateGenerator::GetRandomMonth(){
    return GetRandomInt(1, 12);
}
int DateGenerator::GetRandomDay(int year, int month){
    int max_val = MaxDayInMonth(year, month);
    return GetRandomInt(1, max_val);
}
int DateGenerator::GetRandomInt(int min_val, int max_val){
    size_t seed = abs(rand() * rand());
    return seed % (max_val - min_val + 1) + min_val;
}

Date DateGenerator::GetRandomDate(){
    int year = GetRandomYear();
    int month = GetRandomMonth();
    int day = GetRandomDay(year, month);
    return Date(year, month, day);
}