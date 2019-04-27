#ifndef DATE_GENERATOR_H
#define DATE_GENERATOR_H

#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>
#include <cmath>
#include "date.h"

class DateGenerator{
public:
    static Date GetRandomDate();
private:
    static int GetRandomInt(int min_val, int max_val);
    static int GetRandomYear();
    static int GetRandomMonth();
    static int GetRandomDay(int year, int month);
};


#endif