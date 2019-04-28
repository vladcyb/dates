#include "query_handler.h"

void QueryHandler::Handle(const std::string& query) const {
    std::stringstream ss(query);
    std::string first_word;
    ss >> first_word;
    if (first_word == "generate"){
        int count_dates_to_generate;
        std::string output_filename;
        ss >> count_dates_to_generate;
        ss >> output_filename;
        std::ofstream out(output_filename);
        for(int i = 0; i < count_dates_to_generate; ++i){
            out << DateGenerator::GetRandomDate() << endl;
        }
        out.close();
    } else if (first_word == "check"){
        std::string input_filename;
        ss >> input_filename;
        ifstream in(input_filename);
        Date date;
        int count = 0;
        int fails_count = 0;
        string str_date;
        while(getline(in, str_date)){
            ++count;
            if (!IsValidDate(str_date)){
                cout << "  Line " << count << ": " << str_date << " is invalid." << endl;
                ++fails_count;
            }
        }
        cout << "Checked " << count << " lines." << endl;
        cout << fails_count << " dates are invalid. " << endl;
        in.close();
    }
}