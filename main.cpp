#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "date.h"

using namespace std;

int main(){
    ifstream in("in.txt");
    ofstream out("out.txt");
    Date date;
    vector<Date> dates;
    while(in >> date){
        if (!IsValidDate(date)){
            cerr << "Invalid date: " << date << endl;
            exit(1);
        }
        dates.push_back(date);
    }
    for(const Date& date : dates){
        out << date << "  -  " << date.ToRussian() << endl;
    }

    in.close();
    out.close();
    return 0;
}