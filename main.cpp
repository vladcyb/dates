#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "date.h"
#include "date_generator.h"

using namespace std;

int main(){
    // ofstream out("in.txt");

    // for(int i = 0; i < 100000; ++i){
    //     out << DateGenerator::GetRandomDate() << endl;
    // }

    // out.close();
// ======================================================================

    ifstream in("in.txt");
    int count = 0;
    Date date;
    while(in >> date){
        ++count;
        if(!IsValidDate(date)){
            cout << count << ": " << date << " is invalid!" << endl;
        }
    }
    cout << "Checked " <<  count << " dates. " << endl;
    in.close();

    return 0;
}