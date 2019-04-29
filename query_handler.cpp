#include "query_handler.h"
using namespace std;

#define PERMISSION_ERROR "permission denied."

ifstream::pos_type QueryHandler::GetSize(const string& filename) const {
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg();
}
bool QueryHandler::CheckOnFails(stringstream& ss, const string& message) const {
    if (ss.fail()){
        cout << message << endl;
        ss.clear();
        return false;
    }
    return true;
}

bool QueryHandler::CheckWriteAvailable(
    ofstream& out, const string& output_filename) const {
    out.open(output_filename);
    if (!out){
        cout << output_filename << ": " << PERMISSION_ERROR << endl;
        return false;
    }
    return true;
}


void QueryHandler::Handle(const string& query) const {
    stringstream ss(query);
    string first_word;
    ss >> first_word;
    if (first_word == "gen"){
        int count_dates_to_generate;
        string output_filename;
        ss.clear();
        ss >> count_dates_to_generate;
        ss >> output_filename;
        if (!CheckOnFails(ss, "Usage:\n    gen <X> <filename>")){
            return;
        }
        ofstream out;
        if (!CheckWriteAvailable(out, output_filename)){
            return;
        }
        stringstream output_data;
        for(int i = 0; i < count_dates_to_generate; ++i){
            output_data << DateGenerator::GetRandomDate() << endl;
        }
        out << output_data.rdbuf();
        cout << "Generated " << count_dates_to_generate << " dates into "
        << output_filename << endl;
        cout << "Done." << endl;
    } else if (first_word == "ch"){
        string input_filename;
        ss.clear();
        ss >> input_filename;
        if (!CheckOnFails(ss, "Usage:\n    ch <filename>")){
            return;
        }
        ifstream in(input_filename);
        Date date;
        int count = 0;
        int fails_count = 0;
        string str_date;
        while(getline(in, str_date)){
            ++count;
            if (!str_date.size()){
                continue;
            }
            if (!IsValidDate(str_date)){
                cout << "  Line " << count << ": " << str_date << " is invalid." << endl;
                ++fails_count;
            }
        }
        cout << "Checked " << count << " lines." << endl;
        cout << fails_count << " dates are invalid. " << endl;
        cout << "Done." << endl;
    } else if (first_word == "eng") {
        string input_filename;
        string output_filename;
        ss.clear();
        ss >> input_filename >> output_filename;
        if (!CheckOnFails(ss, "Usage:\n   eng <input_file> <output_file>")){
            return;
        }
        if (input_filename == output_filename){
            cout << "Error! Input and output are the same." << endl;
            return;
        }
        ifstream in(input_filename);
        ofstream out;
        if(!CheckWriteAvailable(out, output_filename)){
            return;
        }
        Date date;
        stringstream output_data;
        while(in >> date){
            output_data << date.ToEnglish() << endl;
        }
        out << output_data.rdbuf();
        cout << "Done." << endl;
    } else if (first_word == "sort"){
        string input_filename;
        string output_filename;
        ss.clear();
        ss >> input_filename >> output_filename;
        if (!CheckOnFails(ss, "Usage:\n    sort <input_filename> <output_filename>")){
            return;
        }
        if (input_filename == output_filename){
            cout << "Error! Input and output are the same." << endl;
            return;
        }
        ifstream in(input_filename);
        ofstream out;
        if (!CheckWriteAvailable(out, output_filename)){
            cout << output_filename << ": " << PERMISSION_ERROR << endl;
            return;
        }
        Date date;
        int dates_capacity = GetSize(input_filename) / 11;
        vector<Date> dates;
        dates.reserve(dates_capacity);
        while(in >> date){
            dates.push_back(date);
        }
        sort(dates.begin(), dates.end());
        stringstream output_data;
        for(const auto& date : dates){
            output_data << date << endl;
        }
        out << output_data.rdbuf();
        cout << "Done." << endl;
    }
}