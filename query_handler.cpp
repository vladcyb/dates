#include "query_handler.h"
#define PERMISSION_ERROR "permission denied."

void QueryHandler::Handle(const std::string& query) const {
    std::stringstream ss(query);
    std::string first_word;
    ss >> first_word;
    if (first_word == "gen"){
        int count_dates_to_generate;
        std::string output_filename;
        ss.clear();
        ss >> count_dates_to_generate;
        ss >> output_filename;
        if (ss.fail()){
            cout << "Usage: " << endl;
            cout << "   gen X <filename>" << endl;
            ss.clear();
            return;
        }
        std::ofstream out(output_filename);
        if (!out){
            cout << output_filename << ": " << PERMISSION_ERROR << endl;
            return;
        }
        for(int i = 0; i < count_dates_to_generate; ++i){
            out << DateGenerator::GetRandomDate() << endl;
        }
        out.close();
        cout << "Generated " << count_dates_to_generate << " dates into "
        << output_filename << endl;
        cout << "Done." << endl;
    } else if (first_word == "ch"){
        std::string input_filename;
        ss.clear();
        ss >> input_filename;
        if (ss.fail()){
            cout << "Usage: " << endl;
            cout << "   ch <filename>" << endl;
            ss.clear();
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
        in.close();
        cout << "Done." << endl;
    } else if (first_word == "eng") {
        string input_filename;
        string output_filename;
        ss.clear();
        ss >> input_filename >> output_filename;
        if (ss.fail()){
            cout << "Usage:" << endl;
            cout << "   eng <input_file> <output_file>" << endl;
            return;
        }
        ifstream in(input_filename);
        ofstream out(output_filename);
        if (!out){
            cout << output_filename << ": " << PERMISSION_ERROR << endl;
            return;
        }
        Date date;
        while(in >> date){
            out << date << ' ' << date.ToEnglish() << endl;
        }
        in.close();
        out.close();
        cout << "Done." << endl;
    }
}